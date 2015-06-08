#include  "unqlite-db-20130825-116/unqlite.h"
#include <stdio.h>  /* puts() */

using namespace System;
using namespace System::Runtime::InteropServices;

// Database Engine Handle=================
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_open(unqlite **ppDB,const char *zFilename,unsigned int iMode);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_config(unqlite *pDb,int nOp,...);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_close(unqlite *pDb);
//========================================

// Key/Value Store Interfaces-------------
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_store(unqlite *pDb,const void *pKey,int nKeyLen,const void *pData,unqlite_int64 nDataLen);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_store_fmt(unqlite *pDb,const void *pKey,int nKeyLen,const char *zFormat,...);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_append(unqlite *pDb,const void *pKey,int nKeyLen,const void *pData,unqlite_int64 nDataLen);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_append_fmt(unqlite *pDb,const void *pKey,int nKeyLen,const char *zFormat,...);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_append(unqlite *pDb,const void *pKey,int nKeyLen,const void *pData,unqlite_int64 nDataLen);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_append_fmt(unqlite *pDb,const void *pKey,int nKeyLen,const char *zFormat,...);
//----------------------------------------

// Manual Transaction Manager=============
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_rollback(unqlite *pDb);
//========================================