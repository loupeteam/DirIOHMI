(*
 * File: DirIOHMI.fun
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of DirIOHMI, licensed under the MIT License.
 *)

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
