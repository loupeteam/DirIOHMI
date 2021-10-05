/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: DirIOHMI
 * File: DirIODualPane.c
 * Author: Josh
 * Created: April 27, 2015
 ********************************************************************
 * Implementation of library DirIOHMI
 ********************************************************************/

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

plcbit DirIODualPane(struct DirectoryMgr_HMI_typ* HMI, struct DIOWrap_typ* t)
{
	int index;

	if(HMI==0 || t == 0){
		return 1;
	}
		
	//Handle user initial commands by popping up dialog.
	if(HMI->Main.CopyLeftToRight.CMD == 1){
		MessageBox_AddMsg((UDINT)&"Copy and overwrite files and folders?",(UDINT)&"OK",(UDINT)&HMI->Main.CopyLeftToRight.Confirm,(UDINT)&"Cancel",0);
	}
	if(HMI->Main.CopyRightToLeft.CMD == 1){
		MessageBox_AddMsg((UDINT)&"Copy and overwrite files and folders?",(UDINT)&"OK",(UDINT)&HMI->Main.CopyRightToLeft.Confirm,(UDINT)&"Cancel",0);
	}

	for(index=0;index<2;index++){

		HMI->Pane[index].Browser.Enable = HMI->Enable;
		HMI->Pane[index].Browser.EnableDirectorySearch = 1;
		HMI->Pane[index].Browser.pFileExtList = (UDINT)&HMI->Main.ExtensionList;
		HMI->Pane[index].Browser.MaxExt = sizeof(HMI->Main.ExtensionList)/sizeof(HMI->Main.ExtensionList[0]);
		HMI->Pane[index].IgnoreErrors = 1;
		DirIOPane(&HMI->Pane[index],t);
		
	}
	
	
	//Reset all commands if we didn't handle them
	HMI->Main.CopyLeftToRight.CMD = 0;
	HMI->Main.CopyRightToLeft.CMD = 0;

	if(HMI->Main.CopyLeftToRight.Confirm){

		HMI->Main.CopyLeftToRight.Confirm = 0;
		strcpy(t->IN.PAR.SrcDevice, HMI->Pane[0].Browser.FileDevice);
		strcpy(t->IN.PAR.DestDevice, HMI->Pane[1].Browser.FileDevice);

		strcpy(t->IN.PAR.SrcPath, HMI->Pane[0].Browser.CurrentPath);	
		strcpy(t->IN.PAR.DestPath, HMI->Pane[1].Browser.CurrentPath);	

		strcpy(t->IN.PAR.SrcName, HMI->Pane[0].Browser.FileSelection);
		strcpy(t->IN.PAR.DestName, HMI->Pane[1].Browser.FileSelection);
	
		t->IN.CMD.Copy = 1;				
	}
	
	if(HMI->Main.CopyRightToLeft.Confirm){

		HMI->Main.CopyRightToLeft.Confirm = 0;

		strcpy(t->IN.PAR.SrcDevice, HMI->Pane[1].Browser.FileDevice);
		strcpy(t->IN.PAR.DestDevice, HMI->Pane[0].Browser.FileDevice);

		strcpy(t->IN.PAR.SrcPath, HMI->Pane[1].Browser.CurrentPath);	
		strcpy(t->IN.PAR.DestPath, HMI->Pane[0].Browser.CurrentPath);	

		strcpy(t->IN.PAR.SrcName, HMI->Pane[1].Browser.FileSelection);
		strcpy(t->IN.PAR.DestName, HMI->Pane[0].Browser.FileSelection);

		t->IN.CMD.Copy = 1;				
	}
	
	HMI_Lock(&HMI->Main.CopyLeftToRight.StatusDP);
	HMI_Lock(&HMI->Main.CopyRightToLeft.StatusDP);

	if( t->OUT.STAT.Busy){

		HMI_Show(&HMI->Progress.StatusDP);				

	}
	else if(t->OUT.STAT.Done){

		memset(&t->IN.CMD,0,sizeof(t->IN.CMD));
		HMI_Hide(&HMI->Progress.StatusDP);
		
	}	
	else if( t->OUT.STAT.Error){

		memset(&t->IN.CMD,0,sizeof(t->IN.CMD));
		strcpy(HMI->internal.ErrorString, t->OUT.STAT.ErrorString);
		MessageBox_AddMsg((UDINT)&HMI->internal.ErrorString,(UDINT)&"OK",0,0,0);
		HMI_Hide(&HMI->Progress.StatusDP);
	
	}	
	else{
		if(HMI->Pane[0].Browser.FileIndex>=0){
			HMI_Unlock(&HMI->Main.CopyLeftToRight.StatusDP);
		}
		if(HMI->Pane[1].Browser.FileIndex>=0){
			HMI_Unlock(&HMI->Main.CopyRightToLeft.StatusDP);
		}
	}			
	return t->OUT.STAT.Busy || t->OUT.STAT.Error;
	
}
