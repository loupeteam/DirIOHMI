/*
 * File: DirIOPane.c
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of DirIOHMI, licensed under the MIT License.
 */
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif

	#include "DirIOHMI.h"
	#include <string.h>
	
#ifdef __cplusplus
	};
#endif

plcbit DirIOPane(struct DirectoryMgr_HMI_Browser_typ* Pane, struct DIOWrap_typ* t)
{
		
	if(Pane==0 || t == 0){
		return 1;
	}
	
	Pane->Browser.pFileList = (UDINT)&Pane->FileList;
	Pane->Browser.MaxFiles = sizeof(Pane->FileList)/sizeof(Pane->FileList[0]);
	HMIFileBrowse(&Pane->Browser);

	if(Pane->CreateDirectory.CMD == 1){
		strcpy(t->IN.PAR.DestName, Pane->Browser.FileSelection);
		PromptBox_AddMsg((UDINT)&"New directory Name:",(UDINT)&t->IN.PAR.DestName,(UDINT)&"OK",(UDINT)&Pane->CreateDirectory.Confirm,(UDINT)&"Cancel",0);
	}	
	if(Pane->Delete.CMD == 1){
		strcpy(t->IN.PAR.DestName, Pane->Browser.FileSelection);
		PromptBox_AddMsg((UDINT)&"Confirm Delete",(UDINT)&t->IN.PAR.DestName,(UDINT)&"OK",(UDINT)&Pane->Delete.Confirm,(UDINT)&"Cancel",0);
	}	
	if(Pane->Rename.CMD == 1){
		strcpy(t->IN.PAR.DestName, Pane->Browser.FileSelection);
		PromptBox_AddMsg((UDINT)&"New Name:",(UDINT)&t->IN.PAR.DestName,(UDINT)&"OK",(UDINT)&Pane->Rename.Confirm,(UDINT)&"Cancel",0);
	}
	if(Pane->ToDataObject.CMD == 1){		
		strcpy(t->IN.PAR.DestName, Pane->Browser.FileSelection);
		if((char)t->IN.PAR.DestName[0]==(char)'\\'){
			lstrip(t->IN.PAR.DestName[0],1);
		}
		PromptBox_AddMsg((UDINT)&"Data Object Name:",(UDINT)&t->IN.PAR.DestName,(UDINT)&"OK",(UDINT)&Pane->ToDataObject.Confirm,(UDINT)&"Cancel",0);
	}
	if(Pane->ToFile.CMD == 1
	){
		strcpy(t->IN.PAR.DestDevice, Pane->Browser.FileDevice);		
		strcpy(t->IN.PAR.DestPath, Pane->Browser.CurrentPath);
		strcpy(t->IN.PAR.SrcName, Pane->Browser.FileSelection);		
		if(Pane->Browser.EnableDataObjects){
			PromptBox_AddMsg((UDINT)&"Data Object Name:",(UDINT)&t->IN.PAR.SrcName,(UDINT)&"OK",(UDINT)&Pane->ToFile.Confirm,(UDINT)&"Cancel",0);
		}
	}
	
	
	//Reset all commands if we didn't handle them
	Pane->CreateDirectory.CMD = 0;
	Pane->Delete.CMD = 0;
	Pane->Rename.CMD = 0;
	Pane->ToDataObject.CMD = 0;
	Pane->ToFile.CMD = 0;



	if(Pane->Delete.Confirm){

		Pane->Delete.Confirm = 0;
		
		strcpy(t->IN.PAR.DestDevice, Pane->Browser.FileDevice);

		strcpy(t->IN.PAR.DestPath, Pane->Browser.CurrentPath);	
		strcpy(t->IN.PAR.DestName, Pane->Browser.FileSelection);

		t->IN.CMD.Delete = 1;
		
	}
	
	if(Pane->Rename.Confirm){
	
		Pane->Rename.Confirm = 0;
		
		strcpy(t->IN.PAR.DestDevice, Pane->Browser.FileDevice);

		strcpy(t->IN.PAR.DestPath, Pane->Browser.CurrentPath);	
		strcpy(t->IN.PAR.SrcName, Pane->Browser.FileSelection);
		
		t->IN.CMD.Rename = 1;
		
	}

	if(Pane->CreateDirectory.Confirm){
	
		Pane->CreateDirectory.Confirm = 0;
		
		strcpy(t->IN.PAR.DestDevice, Pane->Browser.FileDevice);
		strcpy(t->IN.PAR.DestPath, Pane->Browser.CurrentPath);	
		
		t->IN.CMD.CreateDirectory = 1;
		
	}
	
	if(Pane->ToDataObject.Confirm){

		Pane->ToDataObject.Confirm=	0;

		strcpy(t->IN.PAR.SrcDevice,Pane->Browser.FileDevice);		
		strcpy(t->IN.PAR.SrcPath, Pane->Browser.CurrentPath);
		strcpy(t->IN.PAR.SrcName, Pane->Browser.FileSelection);
		strcpy(t->IN.PAR.DestDevice,Pane->Browser.FileDevice);
		
		t->IN.CMD.ConvertToDataObject= 1;
		
	}

	if(Pane->ToFile.Confirm){

		Pane->ToFile.Confirm=	0;
		strcpy(t->IN.PAR.DestPath,Pane->Browser.CurrentPath);
		strcpy(t->IN.PAR.DestName,Pane->Browser.FileSelection);		
		strcpy(t->IN.PAR.DestDevice,Pane->Browser.FileDevice);		
		t->IN.CMD.ConvertToFile= 1;
		
	}
	
	HMI_Lock(&Pane->CreateDirectory.StatusDP);
	HMI_Lock(&Pane->Delete.StatusDP);
	HMI_Lock(&Pane->Rename.StatusDP);

	if( t->OUT.STAT.Busy){

		HMI_Show(&Pane->Progress.StatusDP);				

	}
	else if(t->OUT.STAT.Done){

		memset(&t->IN.CMD,0,sizeof(t->IN.CMD));
		HMI_Hide(&Pane->Progress.StatusDP);		

	}	
	else if( t->OUT.STAT.Error && !Pane->IgnoreErrors){

		memset(&t->IN.CMD,0,sizeof(t->IN.CMD));
		strcpy(Pane->ErrorString, t->OUT.STAT.ErrorString);
		MessageBox_AddMsg( (UDINT)&Pane->ErrorString,(UDINT)&"OK",0,0,0);	
		HMI_Hide(&Pane->Progress.StatusDP);		

	}
	else{
		if(Pane->Browser.FileIndex>=0){
			HMI_Unlock(&Pane->Delete.StatusDP);
			HMI_Unlock(&Pane->Rename.StatusDP);
		}
		HMI_Unlock(&Pane->CreateDirectory.StatusDP);
	}
		
	return t->OUT.STAT.Busy || t->OUT.STAT.Error;
	
}
