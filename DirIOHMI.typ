(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: DirIOHMI
 * File: DirIOHMI.typ
 * Author: Josh
 * Created: April 27, 2015
 ********************************************************************
 * Data types of library DirIOHMI
 ********************************************************************)

TYPE
	DirectoryMgr_HMI_typ : 	STRUCT 
		Enable : BOOL;
		Main : DirectoryMgr_HMI_Main_typ;
		Pane : ARRAY[0..1]OF DirectoryMgr_HMI_Browser_typ;
		Progress : DirectoryMgr_HMI_Progress_typ;
		internal : DirectoryMgr_internal_typ;
	END_STRUCT;
	DirectoryMgr_HMI_Main_typ : 	STRUCT 
		CopyLeftToRight : HMI_Button_typ;
		CopyRightToLeft : HMI_Button_typ;
		ExtensionList : ARRAY[0..9]OF STRING[260];
	END_STRUCT;
	DirectoryMgr_HMI_Browser_typ : 	STRUCT 
		CreateDirectory : HMI_Button_typ;
		Delete : HMI_Button_typ;
		Rename : HMI_Button_typ;
		ToFile : HMI_Button_typ;
		ToDataObject : HMI_Button_typ;
		Browser : HMIFileBrowse;
		Progress : DirectoryMgr_HMI_Progress_typ;
		FileList : ARRAY[0..19]OF STRING[260];
		IgnoreErrors : USINT;
		ErrorString : STRING[DIOWRAP_STRLEN_ERROR];
	END_STRUCT;
	DirectoryMgr_HMI_Progress_typ : 	STRUCT 
		StatusDP : UINT;
		Progress : UDINT;
	END_STRUCT;
	DirectoryMgr_internal_typ : 	STRUCT 
		ErrorString : STRING[DIOWRAP_STRLEN_ERROR];
	END_STRUCT;
END_TYPE
