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
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_fetch(
      unqlite *pDb,
      const void *pKey,int nKeyLen,
      void *pBuf,
      unqlite_int64 *pSize /* IN: Buffer Size / OUT: Record Data Size */
 );
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_fetch_callback(
      unqlite *pDb,
      const void *pKey,int nKeyLen,
      int (*xConsumer)(const void *pData,unsigned int iDataLen,void *pUserData),
      void *pUserData
 );
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_delete(unqlite *pDb,const void *pKey,int nKeyLen);
//----------------------------------------

// Document Store (JSON via Jx9) Interfaces
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_compile(
    unqlite *pDb,
    const char *zJx9,
    int nLen,
    unqlite_vm **ppOutVm
);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_compile_file(
    unqlite *pDb,
    const char *zFile,
    unqlite_vm **ppOutVm
);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_vm_config(unqlite_vm *pVm,int iOp,...);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_vm_exec(unqlite_vm *pVm);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_vm_reset(unqlite_vm *pVm);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_vm_release(unqlite_vm *pVm);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern unqlite_value * unqlite_vm_extract_variable(unqlite_vm *pVm,const char *zVarname);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_vm_dump(
      unqlite_vm *pVm,
      int (*xConsumer)(const void *pDump, unsigned int nLen, void *pUserData),
      void *pUserData
);
// =======================================

// Cursor Iterator Interfaces-------------
// Opening Database Cursors
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_init(unqlite *pDb,unqlite_kv_cursor **ppOut);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_release(unqlite *pDb,unqlite_kv_cursor *pCur);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_reset(unqlite_kv_cursor *pCursor);
// Positioning Database Cursors
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_seek(unqlite_kv_cursor *pCursor,const void *pKey,int nKeyLen,int iPos);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_first_entry(unqlite_kv_cursor *pCursor);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_last_entry(unqlite_kv_cursor *pCursor);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_valid_entry(unqlite_kv_cursor *pCursor);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_next_entry(unqlite_kv_cursor *pCursor);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_prev_entry(unqlite_kv_cursor *pCursor);
// Extracting Data from Database Cursors
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_key(unqlite_kv_cursor *pCursor,void *pBuf,int *pnByte);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_key_callback(unqlite_kv_cursor *pCursor,int (*xConsumer)(const void *,unsigned int,void *),void *pUserData);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_data(unqlite_kv_cursor *pCursor,void *pBuf,unqlite_int64 *pnData);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_data_callback(unqlite_kv_cursor *pCursor,int (*xConsumer)(const void *,unsigned int,void *),void *pUserData);
// Deleting Records using Database Cursors
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_kv_cursor_delete_entry(unqlite_kv_cursor *pCursor);
//----------------------------------------

// Manual Transaction Manager=============
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_begin(unqlite *pDb);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_commit(unqlite *pDb);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_rollback(unqlite *pDb);
//========================================

// Utility Interfaces---------------------
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_util_load_mmaped_file(const char *zFile,void **ppMap,unqlite_int64 *pFileSize);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_util_release_mmaped_file(void *pMap,unqlite_int64 iFileSize);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_util_random_string(unqlite *pDb,char *zBuf,unsigned int buf_size);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern unsigned int unqlite_util_random_num(unqlite *pDb);
//----------------------------------------

// In-process Extending Interfaces========
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_create_function(
    unqlite_vm *pVm,
    const char *zName,
    int (*xFunc)(unqlite_context *pCtx,int argc,unqlite_value **argv),
    void *pUserData
);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_delete_function(unqlite_vm *pVm,const char *zName);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqite_create_constant(
    unqlite_vm *pVm,
    const char *zName,
    void (*xExpand)(unqlite_value *pValue,void *pUserData),
    void *pUserData
);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_delete_constant(unqlite_vm *pVm,const char *zName);
//========================================

// On Demand Object Allocation Interfaces-
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern unqlite_value * unqlite_vm_new_scalar(unqlite_vm *pVm);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern unqlite_value * unqlite_vm_new_array(unqlite_vm *pVm);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_vm_release_value(unqlite_vm *pVm,unqlite_value *pValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern unqlite_value * unqlite_context_new_scalar(unqlite_context *pCtx);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern unqlite_value * unqlite_context_new_array(unqlite_context *pCtx);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern void unqlite_context_release_value(unqlite_context *pCtx,unqlite_value *pValue);
//----------------------------------------

// Obtaining Object Values================
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_to_int(unqlite_value *pValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_to_bool(unqlite_value *pValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern unqlite_int64 unqlite_value_to_int64(unqlite_value *pValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern double unqlite_value_to_double(unqlite_value *pValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern const char * unqlite_value_to_string(unqlite_value *pValue,int *pLen);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern void * unqlite_value_to_resource(unqlite_value *pValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_compare(unqlite_value *pLeft,unqlite_value *pRight,int bStrict);
//========================================

// Setting The Result Of A Foreign Function
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_result_int(unqlite_context *pCtx,int iValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_result_int64(unqlite_context *pCtx,unqlite_int64 iValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_result_bool(unqlite_context *pCtx,int iBool);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_result_double(unqlite_context *pCtx,double Value);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_result_null(unqlite_context *pCtx);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_result_string(unqlite_context *pCtx,const char *zString,int nLen);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_result_string_format(unqlite_context *pCtx,const char *zFormat,...);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_result_value(unqlite_context *pCtx,unqlite_value *pValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_result_resource(unqlite_context *pCtx,void *pUserData);
//----------------------------------------

// Call Context handling Interfaces=======
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_context_output(unqlite_context *pCtx,const char *zString,int nLen);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_context_output_format(unqlite_context *pCtx,const char *zFormat,...);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_context_throw_error(unqlite_context *pCtx,int iErr,const char *zErr);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_context_throw_error_format(unqlite_context *pCtx,int iErr,const char *zFormat,...);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern void * unqlite_context_user_data(unqlite_context *pCtx);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern unsigned int unqlite_context_random_num(unqlite_context *pCtx);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_context_random_string(unqlite_context *pCtx,char *zBuf,int nBuflen);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_context_push_aux_data(unqlite_context *pCtx,void *pUserData);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern void * unqlite_context_peek_aux_data(unqlite_context *pCtx);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern void * unqlite_context_pop_aux_data(unqlite_context *pCtx);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern unsigned int unqlite_context_result_buf_length(unqlite_context *pCtx);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern const char * unqlite_function_name(unqlite_context *pCtx);
//========================================

// JSON Arrays/Objects Management Interfaces
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_array_walk(
      unqlite_value *pArray,
      int (*xWalk)(unqlite_value *pKey,unqlite_value *pValue,void *pUserData),
      void *pUserData
);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern unqlite_value * unqlite_array_fetch(unqlite_value *pArray,const char *zKey,int nByte);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_array_add_elem(unqlite_value *pArray,unqlite_value *pKey,unqlite_value *pValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_array_add_strkey_elem(unqlite_value *pArray,const char *zKey,unqlite_value *pValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_array_count(unqlite_value *pArray);
//----------------------------------------

// Dynamically Typed Object===============
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_is_int(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_is_float(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_is_bool(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_is_string(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_is_null(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_is_numeric(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_is_callable(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_is_scalar(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_is_json_array(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_is_json_object(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_is_resource(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_is_empty(unqlite_value *pVal);
//========================================

// Populating Dynamically Typed Object----
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_int(unqlite_value *pVal,int iValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_int64(unqlite_value *pVal,unqlite_int64 iValue);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_bool(unqlite_value *pVal,int iBool);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_null(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_double(unqlite_value *pVal,double Value);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_string(unqlite_value *pVal,const char *zString,int nLen);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_string_format(unqlite_value *pVal,const char *zFormat,...);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_reset_string_cursor(unqlite_value *pVal);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_value_resource(unqlite_value *pVal,void *pUserData);
//----------------------------------------

// Call Context Memory Management Interfaces
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern void * unqlite_context_alloc_chunk(unqlite_context *pCtx,unsigned int nByte,int ZeroChunk,int AutoRelease);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern void * unqlite_context_realloc_chunk(unqlite_context *pCtx,void *pChunk,unsigned int nByte);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern void unqlite_context_free_chunk(unqlite_context *pCtx,void *pChunk);
//========================================

// Global Library Management Interfaces---
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_lib_config(int nConfigOp,...);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_lib_init(void);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_lib_shutdown(void);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern int unqlite_lib_is_threadsafe(void);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern const char * unqlite_lib_version(void);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern const char * unqlite_lib_signature(void);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern const char * unqlite_lib_ident(void);
[DllImport("unqlite.dll", CallingConvention=CallingConvention::Cdecl)]
extern const char * unqlite_lib_copyright(void);
//----------------------------------------



