(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: DirIOHMI
 * File: DirIOHMI.fun
 * Author: Josh
 * Created: April 27, 2015
 ********************************************************************
 * Functions and function blocks of library DirIOHMI
 ********************************************************************)

FUNCTION DirIODualPane : BOOL (* *) (*$GROUP=User*)
	VAR_INPUT
		HMI : DirectoryMgr_HMI_typ;
	END_VAR
	VAR_IN_OUT
		t : DIOWrap_typ;
	END_VAR
END_FUNCTION

FUNCTION DirIOPane : BOOL (* *) (*$GROUP=User*)
	VAR_INPUT
		Pane : DirectoryMgr_HMI_Browser_typ;
	END_VAR
	VAR_IN_OUT
		t : DIOWrap_typ;
	END_VAR
END_FUNCTION
