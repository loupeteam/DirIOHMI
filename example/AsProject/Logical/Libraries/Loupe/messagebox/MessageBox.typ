(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: MessageBox
 * File: MessageBox.typ
 * Author: Josh
 * Created: August 01, 2013
 ********************************************************************
 * Data types of library MessageBox
 ********************************************************************)
(*Popup HMI Control*)

TYPE
	MessageBox_HMI_typ : 	STRUCT 
		Layer : MessageBox_Layer_typ;
		TextSnippets : MessageBox_TextSnippets;
		Prompt : HMI_TextBox_typ;
		UserInput : HMI_TextBox_typ;
		Buttons1 : HMI_Button_typ;
		Buttons2 : HMI_Button_typ;
		Buttons3 : HMI_Button_typ;
		Buttons4 : HMI_Button_typ;
		Buttons5 : HMI_Button_typ;
		Internal : MessageBox_HMI_Internal_typ;
	END_STRUCT;
END_TYPE

(*Popup HMI Mapping*)

TYPE
	MessageBox_TextSnippets : 	STRUCT 
		Message : STRING[260];
		UserString : STRING[260];
		Buttons1 : STRING[80];
		Buttons2 : STRING[80];
		Buttons3 : STRING[80];
		Buttons4 : STRING[80];
		Buttons5 : STRING[80];
	END_STRUCT;
	MessageBox_Layer_typ : 	STRUCT 
		Active : BOOL;
		Status : UINT;
	END_STRUCT;
END_TYPE

(*Structure to create a message*)

TYPE
	MessageBox_Message_typ : 	STRUCT 
		Prompt : MessageBox_Message_Prompt_typ;
		Buttons : ARRAY[0..4]OF MessageBox_Button_typ;
		pUserString : UDINT;
		MessageID : UDINT;
	END_STRUCT;
	MessageBox_Message_Prompt_typ : 	STRUCT 
		pText : UDINT;
		Index : UINT;
	END_STRUCT;
	MessageBox_Button_typ : 	STRUCT 
		pText : UDINT;
		Index : UINT;
		pCmd : UDINT;
	END_STRUCT;
END_TYPE

(*Popup Backend*)

TYPE
	MessageBox_typ : 	STRUCT 
		Internal : MessageBox_Internal_typ;
	END_STRUCT;
	MessageBox_Internal_typ : 	STRUCT 
		Buffer : Buffer_typ;
	END_STRUCT;
	MessageBox_HMI_Internal_typ : 	STRUCT 
		Message : MessageBox_Message_typ;
		_Show : BOOL;
		_CMD : ARRAY[0..4]OF BOOL;
		_ShowEdge : BOOL;
		_ShowDelay : TON;
		_MessageID : UDINT;
	END_STRUCT;
END_TYPE

(*Errors*)

TYPE
	MESSAGE_ERR : 
		(
		MESSAGE_ERR_INVALID_ID,
		MESSAGE_ERR_ALREADY_INIT,
		MESSAGE_ERR_OUT_OF_MEMORY,
		MESSAGE_ERR_BUFFER_FULL,
		MESSAGE_ERR_UNINITIALIZED,
		MESSAGE_ERR_EMPTY,
		MESSAGE_ERR_INVALID_POINTER,
		MESSAGE_ERR_
		);
END_TYPE
