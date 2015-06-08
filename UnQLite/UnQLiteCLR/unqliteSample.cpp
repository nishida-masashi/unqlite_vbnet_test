#include "unqliteWrapper.h"
#include "unqliteSample.h"


#pragma region "Database Engine Handle"

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

#pragma endregion

#pragma region "Key/Value Store Interfaces"

void unqliteSample::smp_unqlite_kv_store(RichTextBox ^rtb)
{
	rtb->Text = "void unqliteSample::smp_unqlite_kv_store(RichTextBox ^rtb) \n";

	int i,rc;
	unqlite *pDb;

	// Open our database;
	rc = unqlite_open(&pDb,"test.db",UNQLITE_OPEN_CREATE);
	if( rc != UNQLITE_OK ){ return; }

	//Store 100 random records.

	for(i = 0 ; i < 100 ; ++i ){

		char zKey[12]; //Random generated key

		char zData[34]; //Dummy data



		// generate the random key

		unqlite_util_random_string(pDb,zKey,sizeof(zKey));



		// Perform the insertion

		rc = unqlite_kv_store(pDb,zKey,sizeof(zKey),zData,sizeof(zData));

		if( rc != UNQLITE_OK ){

			break;

		}

		if( i == 79 ){

			//Insert a sentinel record

			rc = unqlite_kv_store_fmt(pDb,"sentinel",-1,"This record was inserted on %d:%d:%d",14,9,27);

			if( rc != UNQLITE_OK ){

				break;

			}

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

void unqliteSample::smp_unqlite_kv_append(RichTextBox ^rtb)
{
	rtb->Text = "void unqliteSample::smp_unqlite_kv_append(RichTextBox ^rtb) \n";

	int rc;
	unqlite *pDb;

	// Open our database;
	rc = unqlite_open(&pDb,"test.db",UNQLITE_OPEN_CREATE);
	if( rc != UNQLITE_OK ){ return; }

	//First data chunk .

	rc = unqlite_kv_append(pDb,"msg",-1,"Hello, ",7); //msg => 'Hello, '

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

void unqliteSample::smp_unqlite_kv_store_fmt(RichTextBox ^rtb)
{
	rtb->Text = "void unqliteSample::smp_unqlite_kv_store_fmt(RichTextBox ^rtb) \n";

	int i,rc;
	unqlite *pDb;

	// Open our database;
	rc = unqlite_open(&pDb,"test.db",UNQLITE_OPEN_CREATE);
	if( rc != UNQLITE_OK ){ return; }

	//Store 100 random records.

	for(i = 0 ; i < 100 ; ++i ){

		char zKey[12]; //Random generated key

		char zData[34]; //Dummy data



		// generate the random key

		unqlite_util_random_string(pDb,zKey,sizeof(zKey));



		// Perform the insertion

		rc = unqlite_kv_store(pDb,zKey,sizeof(zKey),zData,sizeof(zData));

		if( rc != UNQLITE_OK ){

			break;

		}

		if( i == 79 ){

			//Insert a sentinel record

			rc = unqlite_kv_store_fmt(pDb,"sentinel",-1,"This record was inserted on %d:%d:%d",14,9,27);

			if( rc != UNQLITE_OK ){

				break;

			}

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

void unqliteSample::smp_unqlite_kv_append_fmt(RichTextBox ^rtb)
{
	rtb->Text = "void unqliteSample::smp_unqlite_kv_append_fmt(RichTextBox ^rtb) \n";

	int rc;
	unqlite *pDb;

	// Open our database;
	rc = unqlite_open(&pDb,"test.db",UNQLITE_OPEN_CREATE);
	if( rc != UNQLITE_OK ){ return; }

	//First data chunk .

	rc = unqlite_kv_append(pDb,"msg",-1,"Hello, ",7); //msg => 'Hello, '

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

void unqliteSample::smp_unqlite_kv_fetch_dynamically(RichTextBox ^rtb)
{
	rtb->Text = "void unqliteSample::smp_unqlite_kv_fetch_dynamically(RichTextBox ^rtb) \n";

}

void unqliteSample::smp_unqlite_kv_fetch_statically(RichTextBox ^rtb)
{
	rtb->Text = "void unqliteSample::smp_unqlite_kv_fetch_statically(RichTextBox ^rtb) \n";

}

void unqliteSample::smp_unqlite_kv_fetch_callback(RichTextBox ^rtb)
{
	rtb->Text = "void unqliteSample::smp_unqlite_kv_fetch_callback(RichTextBox ^rtb) \n";

}

void unqliteSample::smp_unqlite_kv_delete(RichTextBox ^rtb)
{
	rtb->Text = "void unqliteSample::smp_unqlite_kv_delete(RichTextBox ^rtb) \n";

	int rc;
	unqlite *pDb;

	// Open our database;
	rc = unqlite_open(&pDb,"test.db",UNQLITE_OPEN_READWRITE);
	if( rc != UNQLITE_OK ){ return; }

	//Store some records unqlite_kv_append, unqlite_kv_store...

	//Delete a record

	rc = unqlite_kv_delete(pDb,"SomeRecord",-1);

	if( rc != UNQLITE_OK ){

		const char *zBuf;

		int iLen;

		/* Extract database error log */

		unqlite_config(pDb,UNQLITE_CONFIG_ERR_LOG,&zBuf,&iLen);

		if( iLen > 0 ){

			puts(zBuf);

			String^ str = gcnew String(zBuf);
			rtb->Text += str;
		}

		if( rc != UNQLITE_BUSY && rc != UNQLITE_NOTFOUND ){

			/* Rollback */
			unqlite_rollback(pDb);

		}

	}

	//Auto-commit the transaction and close our handle
	unqlite_close(pDb);
}

void unqliteSample::smp_unqlite_kv_config(RichTextBox ^rtb)
{
	rtb->Text = "void unqliteSample::smp_unqlite_kv_config(RichTextBox ^rtb) \n";
	
}

#pragma endregion

#pragma region "Document Store (JSON via Jx9) Interfaces"

//void unqliteSample::smp_unqlite_config(RichTextBox ^rtb)
//{
//	rtb->Text = "void unqliteSample::smp_unqlite_config(RichTextBox ^rtb) \n";
//	
//	String^ str = gcnew String(zBuf);
//			rtb->Text += str;
//}

#pragma endregion

#pragma region ""

//void unqliteSample::smp_unqlite_config(RichTextBox ^rtb)
//{
//	rtb->Text = "void unqliteSample::smp_unqlite_config(RichTextBox ^rtb) \n";
//	
//	String^ str = gcnew String(zBuf);
//			rtb->Text += str;
//}

#pragma endregion


