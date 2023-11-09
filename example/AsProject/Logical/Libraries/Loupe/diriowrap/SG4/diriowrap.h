/* Automation Studio generated header file */
/* Do not edit ! */
/* diriowrap 0.00.8 */

#ifndef _DIRIOWRAP_
#define _DIRIOWRAP_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _diriowrap_VERSION
#define _diriowrap_VERSION 0.00.8
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "AsBrStr.h"
		#include "DataObj.h"
		#include "FileIO.h"
		#include "sys_lib.h"
#endif
#ifdef _SG4
		#include "AsBrStr.h"
		#include "DataObj.h"
		#include "FileIO.h"
		#include "sys_lib.h"
#endif
#ifdef _SGC
		#include "AsBrStr.h"
		#include "DataObj.h"
		#include "FileIO.h"
		#include "sys_lib.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define DIOWRAP_STRLEN_ERROR 80U
 #define DIOWRAP_STRLEN_NAME 260U
 #define DIOWRAP_STAT_OK 0U
 #define DIOWRAP_STAT_DISABLED 65534U
#else
 _GLOBAL_CONST unsigned char DIOWRAP_STRLEN_ERROR;
 _GLOBAL_CONST unsigned short DIOWRAP_STRLEN_NAME;
 _GLOBAL_CONST unsigned short DIOWRAP_STAT_OK;
 _GLOBAL_CONST unsigned short DIOWRAP_STAT_DISABLED;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct LoadDatObjVolatile_internal_typ
{	struct DatObjInfo DatObjInfo;
	struct DatObjRead DatObjRead;
	unsigned short AllocStatus;
	plcbit _Active;
} LoadDatObjVolatile_internal_typ;

typedef struct ReadDataObjectVolatile
{
	/* VAR_INPUT (analog) */
	plcstring DataObjectName[11];
	/* VAR_OUTPUT (analog) */
	unsigned long pData;
	unsigned long DataLen;
	unsigned short Status;
	/* VAR (analog) */
	struct LoadDatObjVolatile_internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
} ReadDataObjectVolatile_typ;

typedef struct CreateWriteFile_internal_typ
{	struct FileCreate FileCreate;
	struct FileWrite FileWrite;
	struct FileClose FileClose;
	plcbit _Active;
	plcbit _Open;
	plcbit _Execute;
} CreateWriteFile_internal_typ;

typedef struct CreateFile
{
	/* VAR_INPUT (analog) */
	plcstring FileDevice[81];
	plcstring FileName[81];
	unsigned long pData;
	unsigned long DataLen;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	/* VAR (analog) */
	struct CreateWriteFile_internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
} CreateFile_typ;

typedef struct DataObjToFile_internal_typ
{	struct ReadDataObjectVolatile ReadDataObject;
	struct CreateFile CreateFile;
	plcbit _Execute;
} DataObjToFile_internal_typ;

typedef struct DataObjToFile
{
	/* VAR_INPUT (analog) */
	plcstring FileDevice[81];
	plcstring FileName[81];
	plcstring DataObjectName[11];
	/* VAR_OUTPUT (analog) */
	plcstring ExportFileName[81];
	unsigned short Status;
	/* VAR (analog) */
	struct DataObjToFile_internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
} DataObjToFile_typ;

typedef struct LoadFileVolatile_internal_typ
{	struct FileOpen FileOpen;
	struct FileRead FileRead;
	struct FileClose FileClose;
	unsigned short AllocStatus;
	plcbit _Open;
	plcbit _Active;
} LoadFileVolatile_internal_typ;

typedef struct ReadFileVolatile
{
	/* VAR_INPUT (analog) */
	plcstring FileDevice[81];
	plcstring FileName[81];
	/* VAR_OUTPUT (analog) */
	unsigned long pData;
	unsigned long DataLen;
	unsigned short Status;
	/* VAR (analog) */
	struct LoadFileVolatile_internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
} ReadFileVolatile_typ;

typedef struct CreateDataObject_internal_typ
{	struct DatObjCreate CreateDataObject;
	plcbit _Execute;
} CreateDataObject_internal_typ;

typedef struct CreateDataObject
{
	/* VAR_INPUT (analog) */
	plcstring DataObjectName[11];
	unsigned long pData;
	unsigned long DataLen;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	/* VAR (analog) */
	struct CreateDataObject_internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
} CreateDataObject_typ;

typedef struct FileToDataObj_internal_typ
{	struct ReadFileVolatile ReadFile;
	struct CreateDataObject CreateDataObject;
	unsigned long DataLength;
	unsigned short AllocStatus;
	unsigned long pData;
	plcbit _Execute;
	plcbit _Active;
} FileToDataObj_internal_typ;

typedef struct FileToDataObj
{
	/* VAR_INPUT (analog) */
	plcstring FileDevice[81];
	plcstring FileName[81];
	plcstring DataObjectName[11];
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	/* VAR (analog) */
	struct FileToDataObj_internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
} FileToDataObj_typ;

typedef struct DIODelegate_typ
{	plcbit Active;
	plcbit enable;
	unsigned char Execute;
	plcstring DataObjectName[11];
	plcstring FileDevice[21];
	plcstring FileName[81];
	plcstring TempFileDevice[21];
	unsigned short Status;
	plcstring DestPath[81];
} DIODelegate_typ;

typedef struct DIOWrap_Int_FUB_typ
{	struct DirCreate Create;
	struct DirRename Rename;
	struct DirCopy Copy;
	struct DirDeleteEx Delete;
	struct FileRename RenameFile;
	struct FileCopy CopyFile;
	struct FileDelete DeleteFile;
	struct DataObjToFile ConvertToFile;
	struct FileToDataObj ConvertToDataObject;
	struct DIODelegate_typ Zip;
	struct DIODelegate_typ Unzip;
	struct DIODelegate_typ ConvertFolderToDataObject;
	struct DIODelegate_typ ConvertToFolder;
} DIOWrap_Int_FUB_typ;

typedef struct DIOWrap_IN_CMD_typ
{	plcbit CreateDirectory;
	plcbit Rename;
	plcbit Copy;
	plcbit Move;
	plcbit Delete;
	plcbit ConvertToFile;
	plcbit ExtractDataObject;
	plcbit ConvertToDataObject;
	plcbit Zip;
	plcbit Unzip;
} DIOWrap_IN_CMD_typ;

typedef struct DIOWrap_Internal_typ
{	struct DIOWrap_Int_FUB_typ FUB;
	struct DIOWrap_IN_CMD_typ CMD;
	unsigned long NewFileIndex;
	plcstring SrcName[261];
	plcstring DstName[261];
} DIOWrap_Internal_typ;

typedef struct DIOWrap_OUT_STAT_typ
{	plcbit Busy;
	plcbit Done;
	plcbit Error;
	unsigned short ErrorID;
	plcstring ErrorString[81];
} DIOWrap_OUT_STAT_typ;

typedef struct DIOWrap_OUT_typ
{	struct DIOWrap_OUT_STAT_typ STAT;
} DIOWrap_OUT_typ;

typedef struct DIOWrap_IN_PAR_typ
{	plcstring SrcDevice[261];
	plcstring SrcPath[261];
	plcstring SrcName[261];
	plcstring DestDevice[261];
	plcstring DestPath[261];
	plcstring DestName[261];
} DIOWrap_IN_PAR_typ;

typedef struct DIOWrap_IN_typ
{	struct DIOWrap_IN_CMD_typ CMD;
	struct DIOWrap_IN_PAR_typ PAR;
} DIOWrap_IN_typ;

typedef struct DIOWrap_typ
{	struct DIOWrap_IN_typ IN;
	struct DIOWrap_OUT_typ OUT;
	struct DIOWrap_Internal_typ Internal;
} DIOWrap_typ;

typedef struct DeleteDatObj_internal_typ
{	struct DatObjInfo DatObjInfo;
	struct DatObjDelete DatObjDelete;
	plcbit _Active;
	plcbit _Execute;
} DeleteDatObj_internal_typ;

typedef struct DeleteDataObject
{
	/* VAR_INPUT (analog) */
	plcstring DataObjectName[11];
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	/* VAR (analog) */
	struct DeleteDatObj_internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
} DeleteDataObject_typ;

typedef struct AppendDataObject_internal_typ
{	struct ReadDataObjectVolatile ReadDataObject;
	struct DeleteDataObject DeleteDataObject;
	struct CreateDataObject WriteDataObject;
	unsigned long DataLength;
	unsigned long pData;
	unsigned short AllocStatus;
	plcbit _Execute;
	plcbit _Active;
} AppendDataObject_internal_typ;

typedef struct DataObjectFileHeader_typ
{	plcstring HEAD[8];
	plcstring FileName[81];
	unsigned long FileSize;
} DataObjectFileHeader_typ;

typedef struct AppendDataObject
{
	/* VAR_INPUT (analog) */
	plcstring DataObjectName[11];
	unsigned long pData;
	unsigned long DataLen;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	/* VAR (analog) */
	struct AppendDataObject_internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
} AppendDataObject_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void ReadFileVolatile(struct ReadFileVolatile* inst);
_BUR_PUBLIC void ReadDataObjectVolatile(struct ReadDataObjectVolatile* inst);
_BUR_PUBLIC void DeleteDataObject(struct DeleteDataObject* inst);
_BUR_PUBLIC void CreateFile(struct CreateFile* inst);
_BUR_PUBLIC void FileToDataObj(struct FileToDataObj* inst);
_BUR_PUBLIC void DataObjToFile(struct DataObjToFile* inst);
_BUR_PUBLIC void CreateDataObject(struct CreateDataObject* inst);
_BUR_PUBLIC void AppendDataObject(struct AppendDataObject* inst);
_BUR_PUBLIC unsigned short DirIO(struct DIOWrap_typ* t);
_BUR_PUBLIC plcbit ValidDirectoryName(unsigned long Name);


#ifdef __cplusplus
};
#endif
#endif /* _DIRIOWRAP_ */

