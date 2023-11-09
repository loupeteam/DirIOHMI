(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: MessageBox
 * File: MessageBox.fun
 * Author: Josh
 * Created: August 01, 2013
 ********************************************************************
 * Functions and function blocks of library MessageBox
 ********************************************************************)

FUNCTION MessageBox_Init : UDINT (*instantiates a message queue*)
	VAR_INPUT
		QueueSize : USINT;
	END_VAR
END_FUNCTION

FUNCTION MessageBox_AddMsg : UDINT (*adds a normal priority message to the bottom of the list*)
	VAR_INPUT
		Message : UDINT;
		Button1Text : UDINT;
		pCommand1 : UDINT;
		Button2Text : UDINT;
		pCommand2 : UDINT;
	END_VAR
END_FUNCTION

FUNCTION MessageBox_AddMsgTop : UDINT (*adds a high priority message to the top of the list, can bump off the last msg in the buffer*)
	VAR_INPUT
		Message : UDINT;
		Button1Text : UDINT;
		pCommand1 : UDINT;
		Button2Text : UDINT;
		pCommand2 : UDINT;
	END_VAR
END_FUNCTION

FUNCTION PromptBox_AddMsg : UDINT (*adds a normal priority message to the bottom of the list*)
	VAR_INPUT
		Message : UDINT;
		pInputString : UDINT;
		Button1Text : UDINT;
		pCommand1 : UDINT;
		Button2Text : UDINT;
		pCommand2 : UDINT;
	END_VAR
END_FUNCTION

FUNCTION PromptBox_AddMsgTop : UDINT (*adds a high priority message to the top of the list, can bump off the last msg in the buffer*)
	VAR_INPUT
		Message : UDINT;
		pInputString : UDINT;
		Button1Text : UDINT;
		pCommand1 : UDINT;
		Button2Text : UDINT;
		pCommand2 : UDINT;
	END_VAR
END_FUNCTION

FUNCTION MessageBox_RemoveMsg : UDINT (*marks a message for removal based on messageID*)
	VAR_INPUT
		MessageID : UDINT;
	END_VAR
END_FUNCTION

FUNCTION MessageBox_HMI : UDINT (*used to cyclically update messagebox interface with HMI*)
	VAR_INPUT
		MessageBox : MessageBox_HMI_typ;
	END_VAR
END_FUNCTION

FUNCTION MessageBox_Add3BtnMsg : UDINT (*adds a normal priority 3-button message to the bottom of the list*)
	VAR_INPUT
		Message : UDINT;
		Button1Text : UDINT;
		pCommand1 : UDINT;
		Button2Text : UDINT;
		pCommand2 : UDINT;
		Button3Text : UDINT;
		pCommand3 : UDINT;
	END_VAR
END_FUNCTION

FUNCTION MessageBox_Add3BtnMsgTop : UDINT (*adds a high priority 3-button message to the top of the list, can bump off the last msg in the buffer*)
	VAR_INPUT
		Message : UDINT;
		Button1Text : UDINT;
		pCommand1 : UDINT;
		Button2Text : UDINT;
		pCommand2 : UDINT;
		Button3Text : UDINT;
		pCommand3 : UDINT;
	END_VAR
END_FUNCTION

FUNCTION PromptBox_Add3BtnMsg : UDINT (*adds a normal priority 3-button message to the bottom of the list*)
	VAR_INPUT
		Message : UDINT;
		pInputString : UDINT;
		Button1Text : UDINT;
		pCommand1 : UDINT;
		Button2Text : UDINT;
		pCommand2 : UDINT;
		Button3Text : UDINT;
		pCommand3 : UDINT;
	END_VAR
END_FUNCTION

FUNCTION PromptBox_Add3BtnMsgTop : UDINT (*adds a high priority 3-button message to the top of the list, can bump off the last msg in the buffer*)
	VAR_INPUT
		Message : UDINT;
		pInputString : UDINT;
		Button1Text : UDINT;
		pCommand1 : UDINT;
		Button2Text : UDINT;
		pCommand2 : UDINT;
		Button3Text : UDINT;
		pCommand3 : UDINT;
	END_VAR
END_FUNCTION

FUNCTION MessageBox_AddNBtnMsg : UDINT (*adds a normal priority N-button message (N <= 5) to the bottom of the list*)
	VAR_INPUT
		Message : UDINT;
		Button1Text : UDINT;
		pCommand1 : UDINT;
		Button2Text : UDINT;
		pCommand2 : UDINT;
		Button3Text : UDINT;
		pCommand3 : UDINT;
		Button4Text : UDINT;
		pCommand4 : UDINT;
		Button5Text : UDINT;
		pCommand5 : UDINT;
	END_VAR
END_FUNCTION

FUNCTION MessageBox_AddNBtnMsgTop : UDINT (*adds a high priority N-button message (N <= 5) to the top of the list, can bump off the last msg in the buffer*)
	VAR_INPUT
		Message : UDINT;
		Button1Text : UDINT;
		pCommand1 : UDINT;
		Button2Text : UDINT;
		pCommand2 : UDINT;
		Button3Text : UDINT;
		pCommand3 : UDINT;
		Button4Text : UDINT;
		pCommand4 : UDINT;
		Button5Text : UDINT;
		pCommand5 : UDINT;
	END_VAR
END_FUNCTION

FUNCTION PromptBox_AddNBtnMsg : UDINT (*adds a normal priority N-button message (N <= 5) to the bottom of the list*)
	VAR_INPUT
		Message : UDINT;
		pInputString : UDINT;
		Button1Text : UDINT;
		pCommand1 : UDINT;
		Button2Text : UDINT;
		pCommand2 : UDINT;
		Button3Text : UDINT;
		pCommand3 : UDINT;
		Button4Text : UDINT;
		pCommand4 : UDINT;
		Button5Text : UDINT;
		pCommand5 : UDINT;
	END_VAR
END_FUNCTION

FUNCTION PromptBox_AddNBtnMsgTop : UDINT (*adds a high priority N-button message (N <= 5) to the top of the list, can bump off the last msg in the buffer*)
	VAR_INPUT
		Message : UDINT;
		pInputString : UDINT;
		Button1Text : UDINT;
		pCommand1 : UDINT;
		Button2Text : UDINT;
		pCommand2 : UDINT;
		Button3Text : UDINT;
		pCommand3 : UDINT;
		Button4Text : UDINT;
		pCommand4 : UDINT;
		Button5Text : UDINT;
		pCommand5 : UDINT;
	END_VAR
END_FUNCTION
