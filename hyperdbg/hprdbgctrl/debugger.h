/**
 * @file debugger.h
 * @author Sina Karvandi (sina@rayanfam.com)
 * @brief General debugger functions
 * @details
 * @version 0.1
 * @date 2020-05-27
 *
 * @copyright This project is released under the GNU Public License v3.
 *
 */
#pragma once

//////////////////////////////////////////////////
//            	    Structures                  //
//////////////////////////////////////////////////

/**
 * @brief structures related to debugging
 *
 */
typedef struct _DEBUGGING_STATE {
  BOOLEAN IsAttachedToUsermodeProcess;
  UINT64 ConnectedProcessId;
  UINT64 ConnectedThreadId;
} DEBUGGING_STATE, *PDEBUGGING_STATE;

//////////////////////////////////////////////////
//				    Functions                   //
//////////////////////////////////////////////////

BOOLEAN
ShowErrorMessage(UINT32 Error);

BOOLEAN IsTagExist(UINT64 Tag);

BOOLEAN
InterpretConditionsAndCodes(vector<string> *SplittedCommand,
                            BOOLEAN IsConditionBuffer, PUINT64 BufferAddress,
                            PUINT32 BufferLength);

BOOLEAN
SendEventToKernel(PDEBUGGER_GENERAL_EVENT_DETAIL Event,
                  UINT32 EventBufferLength);

BOOLEAN
RegisterActionToEvent(PDEBUGGER_GENERAL_ACTION Action,
                      UINT32 ActionsBufferLength);

BOOLEAN InterpretGeneralEventAndActionsFields(
    vector<string> *SplittedCommand, DEBUGGER_EVENT_TYPE_ENUM EventType,
    PDEBUGGER_GENERAL_EVENT_DETAIL *EventDetailsToFill,
    PUINT32 EventBufferLength, PDEBUGGER_GENERAL_ACTION *ActionDetailsToFill,
    PUINT32 ActionBufferLength);

UINT64 GetNewDebuggerEventTag();

VOID LogopenSaveToFile(const char *Text);

BOOL BreakController(DWORD CtrlType);

VOID CommandEventsShowEvents();

VOID CommandEventsModifyEvents(UINT64 Tag,
                               DEBUGGER_MODIFY_EVENTS_TYPE TypeOfAction);

VOID CommandFlushRequestFlush();

BOOLEAN IsItALocalCommand(string Command);

VOID AttachToProcess(UINT32 TargetPid, UINT32 TargetTid);

VOID DetachFromProcess();
