#include "unqliteWrapper.h"
#include "unqliteSample.h"

void unqliteSample::smp_unqlite_open(RichTextBox ^rtb)
{
	rtb->Text = "void unqliteSample::smp_unqlite_open(RichTextBox ^rtb) \n";

	int rc;
	unqlite *pDb;

	// Open our database;
	rc = unqlite_open(&pDb,"test.db",UNQLITE_OPEN_CREATE);
	if( rc != UNQLITE_OK ){ return; }

	//First data chunk .

	rc = unqlite_kv_store(pDb,"msg",-1,"Hello, ",7); //msg => 'Hello, '

	if( rc == UNQLITE_OK ){

		//The second chunk

		rc = unqlite_kv_append(pDb,"msg",-1,"Current time is: ",17); //msg => 'Hello, Current time is: '

		if( rc == UNQLITE_OK ){

			//The last formatted chunk

			rc = unqlite_kv_append_fmt(pDb,"msg",-1,"%d:%d:%d",10,16,53); //msg => 'Hello, Current time is: 10:16:53'

		}

	}

	if( rc != UNQLITE_OK ){

		const char *zBuf;

		int iLen;

		/* Something goes wrong, extract database error log */

		unqlite_config(pDb,UNQLITE_CONFIG_ERR_LOG,&zBuf,&iLen);

		if( iLen > 0 ){

			puts(zBuf);
			
			String^ str = gcnew String(zBuf);
			rtb->Text += str;
		}

		if( rc != UNQLITE_BUSY && rc != UNQLITE_NOTIMPLEMENTED ){

			/* Rollback */
			unqlite_rollback(pDb);

		}

	}

	//Auto-commit the transaction and close our handle
	unqlite_close(pDb);
}

void unqliteSample::smp_unqlite_config(RichTextBox ^rtb)
{
	rtb->Text = "void unqliteSample::smp_unqlite_config(RichTextBox ^rtb) \n";

}

void unqliteSample::smp_unqlite_close(RichTextBox ^rtb)
{
	rtb->Text = "void unqliteSample::smp_unqlite_close(RichTextBox ^rtb) \n";

}




