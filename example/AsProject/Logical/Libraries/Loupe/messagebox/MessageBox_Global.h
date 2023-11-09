/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: MessageBox
 * File: MessageBox_Global.h
 * Author: Josh
 * Created: Aug 1, 2013
 *******************************************************************/

#include <bur/plctypes.h>
#include <string.h>

MessageBox_typ * MessageBoxList[MESSAGEBOX_MAX+1];
UDINT CurrentMessageID;

unsigned short MessageBox_Get(unsigned short ID , unsigned long MessageBox );
unsigned long MessageBox_AddMsg_full(unsigned short ID , unsigned long Message, unsigned long MessageIndex, unsigned long Buttons, BOOL Priority);
unsigned long PromptBox_AddMsg_full(unsigned short ID , unsigned long Message, unsigned long MessageIndex,unsigned long UserString, unsigned long Buttons, BOOL Priority );
