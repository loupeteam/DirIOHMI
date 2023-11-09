/* Automation Studio generated header file */
/* Do not edit ! */
/* messagebox 0.01.3 */

#ifndef _MESSAGEBOX_
#define _MESSAGEBOX_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _messagebox_VERSION
#define _messagebox_VERSION 0.01.3
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "HMITools.h"
		#include "ringbuflib.h"
#endif
#ifdef _SG4
		#include "HMITools.h"
		#include "ringbuflib.h"
#endif
#ifdef _SGC
		#include "HMITools.h"
		#include "ringbuflib.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define MESSAGEBOX_MAX 5U
 #define MESSAGEBOX_MESSAGE_LENGTH 80U
#else
 _GLOBAL_CONST unsigned short MESSAGEBOX_MAX;
 _GLOBAL_CONST unsigned short MESSAGEBOX_MESSAGE_LENGTH;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum MESSAGE_ERR
{	MESSAGE_ERR_INVALID_ID,
	MESSAGE_ERR_ALREADY_INIT,
	MESSAGE_ERR_OUT_OF_MEMORY,
	MESSAGE_ERR_BUFFER_FULL,
	MESSAGE_ERR_UNINITIALIZED,
	MESSAGE_ERR_EMPTY,
	MESSAGE_ERR_INVALID_POINTER,
	MESSAGE_ERR_
} MESSAGE_ERR;

typedef struct MessageBox_Layer_typ
{	plcbit Active;
	unsigned short Status;
} MessageBox_Layer_typ;

typedef struct MessageBox_TextSnippets
{	plcstring Message[261];
	plcstring UserString[261];
	plcstring Buttons1[81];
	plcstring Buttons2[81];
	plcstring Buttons3[81];
	plcstring Buttons4[81];
	plcstring Buttons5[81];
} MessageBox_TextSnippets;

typedef struct MessageBox_Message_Prompt_typ
{	unsigned long pText;
	unsigned short Index;
} MessageBox_Message_Prompt_typ;

typedef struct MessageBox_Button_typ
{	unsigned long pText;
	unsigned short Index;
	unsigned long pCmd;
} MessageBox_Button_typ;

typedef struct MessageBox_Message_typ
{	struct MessageBox_Message_Prompt_typ Prompt;
	struct MessageBox_Button_typ Buttons[5];
	unsigned long pUserString;
	unsigned long MessageID;
} MessageBox_Message_typ;

typedef struct MessageBox_HMI_Internal_typ
{	struct MessageBox_Message_typ Message;
	plcbit _Show;
	plcbit _CMD[5];
	plcbit _ShowEdge;
	struct TON _ShowDelay;
	unsigned long _MessageID;
} MessageBox_HMI_Internal_typ;

typedef struct MessageBox_HMI_typ
{	struct MessageBox_Layer_typ Layer;
	struct MessageBox_TextSnippets TextSnippets;
	struct HMI_TextBox_typ Prompt;
	struct HMI_TextBox_typ UserInput;
	struct HMI_Button_typ Buttons1;
	struct HMI_Button_typ Buttons2;
	struct HMI_Button_typ Buttons3;
	struct HMI_Button_typ Buttons4;
	struct HMI_Button_typ Buttons5;
	struct MessageBox_HMI_Internal_typ Internal;
} MessageBox_HMI_typ;

typedef struct MessageBox_Internal_typ
{	struct Buffer_typ Buffer;
} MessageBox_Internal_typ;

typedef struct MessageBox_typ
{	struct MessageBox_Internal_typ Internal;
} MessageBox_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC unsigned long MessageBox_Init(unsigned char QueueSize);
_BUR_PUBLIC unsigned long MessageBox_AddMsg(unsigned long Message, unsigned long Button1Text, unsigned long pCommand1, unsigned long Button2Text, unsigned long pCommand2);
_BUR_PUBLIC unsigned long MessageBox_AddMsgTop(unsigned long Message, unsigned long Button1Text, unsigned long pCommand1, unsigned long Button2Text, unsigned long pCommand2);
_BUR_PUBLIC unsigned long PromptBox_AddMsg(unsigned long Message, unsigned long pInputString, unsigned long Button1Text, unsigned long pCommand1, unsigned long Button2Text, unsigned long pCommand2);
_BUR_PUBLIC unsigned long PromptBox_AddMsgTop(unsigned long Message, unsigned long pInputString, unsigned long Button1Text, unsigned long pCommand1, unsigned long Button2Text, unsigned long pCommand2);
_BUR_PUBLIC unsigned long MessageBox_RemoveMsg(unsigned long MessageID);
_BUR_PUBLIC unsigned long MessageBox_HMI(struct MessageBox_HMI_typ* MessageBox);
_BUR_PUBLIC unsigned long MessageBox_Add3BtnMsg(unsigned long Message, unsigned long Button1Text, unsigned long pCommand1, unsigned long Button2Text, unsigned long pCommand2, unsigned long Button3Text, unsigned long pCommand3);
_BUR_PUBLIC unsigned long MessageBox_Add3BtnMsgTop(unsigned long Message, unsigned long Button1Text, unsigned long pCommand1, unsigned long Button2Text, unsigned long pCommand2, unsigned long Button3Text, unsigned long pCommand3);
_BUR_PUBLIC unsigned long PromptBox_Add3BtnMsg(unsigned long Message, unsigned long pInputString, unsigned long Button1Text, unsigned long pCommand1, unsigned long Button2Text, unsigned long pCommand2, unsigned long Button3Text, unsigned long pCommand3);
_BUR_PUBLIC unsigned long PromptBox_Add3BtnMsgTop(unsigned long Message, unsigned long pInputString, unsigned long Button1Text, unsigned long pCommand1, unsigned long Button2Text, unsigned long pCommand2, unsigned long Button3Text, unsigned long pCommand3);
_BUR_PUBLIC unsigned long MessageBox_AddNBtnMsg(unsigned long Message, unsigned long Button1Text, unsigned long pCommand1, unsigned long Button2Text, unsigned long pCommand2, unsigned long Button3Text, unsigned long pCommand3, unsigned long Button4Text, unsigned long pCommand4, unsigned long Button5Text, unsigned long pCommand5);
_BUR_PUBLIC unsigned long MessageBox_AddNBtnMsgTop(unsigned long Message, unsigned long Button1Text, unsigned long pCommand1, unsigned long Button2Text, unsigned long pCommand2, unsigned long Button3Text, unsigned long pCommand3, unsigned long Button4Text, unsigned long pCommand4, unsigned long Button5Text, unsigned long pCommand5);
_BUR_PUBLIC unsigned long PromptBox_AddNBtnMsg(unsigned long Message, unsigned long pInputString, unsigned long Button1Text, unsigned long pCommand1, unsigned long Button2Text, unsigned long pCommand2, unsigned long Button3Text, unsigned long pCommand3, unsigned long Button4Text, unsigned long pCommand4, unsigned long Button5Text, unsigned long pCommand5);
_BUR_PUBLIC unsigned long PromptBox_AddNBtnMsgTop(unsigned long Message, unsigned long pInputString, unsigned long Button1Text, unsigned long pCommand1, unsigned long Button2Text, unsigned long pCommand2, unsigned long Button3Text, unsigned long pCommand3, unsigned long Button4Text, unsigned long pCommand4, unsigned long Button5Text, unsigned long pCommand5);


#ifdef __cplusplus
};
#endif
#endif /* _MESSAGEBOX_ */

