
#using <System.dll>
#using <System.Windows.Forms.dll>
using namespace System::Windows::Forms;

public ref class unqliteSample {

public:
	//Database Engine Handle
	static void smp_unqlite_open(RichTextBox ^rtb); 
	static void smp_unqlite_config(RichTextBox ^rtb);
	static void smp_unqlite_close(RichTextBox ^rtb);

	//Key/Value Store Interfaces
	static void smp_unqlite_kv_store(RichTextBox ^rtb);
	static void smp_unqlite_kv_append(RichTextBox ^rtb);
	static void smp_unqlite_kv_store_fmt(RichTextBox ^rtb);
	static void smp_unqlite_kv_append_fmt(RichTextBox ^rtb);
	static void smp_unqlite_kv_fetch_dynamically(RichTextBox ^rtb);
	static void smp_unqlite_kv_fetch_statically(RichTextBox ^rtb);
	static void smp_unqlite_kv_fetch_callback(RichTextBox ^rtb);
	static void smp_unqlite_kv_delete(RichTextBox ^rtb);
	static void smp_unqlite_kv_config(RichTextBox ^rtb);

};

