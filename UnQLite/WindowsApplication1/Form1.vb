Public Class Form1

#Region "Database Engine Handle"

    Private Sub unqlite_open_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_open.Click
        unqliteSample.smp_unqlite_open(RichTextBox1)
    End Sub

    Private Sub unqlite_config_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_config.Click
        unqliteSample.smp_unqlite_config(RichTextBox1)
    End Sub

    Private Sub unqlite_close_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_close.Click
        unqliteSample.smp_unqlite_close(RichTextBox1)
    End Sub

#End Region

#Region "Key/Value Store Interfaces"

    Private Sub unqlite_kv_store_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_kv_store.Click

    End Sub

    Private Sub unqlite_kv_append_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_kv_append.Click

    End Sub

    Private Sub unqlite_kv_store_fmt_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_kv_store_fmt.Click

    End Sub

    Private Sub unqlite_kv_append_fmt_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_kv_append_fmt.Click

    End Sub

    Private Sub unqlite_kv_fetch_dynamically_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_kv_fetch_dynamically.Click

    End Sub

    Private Sub unqlite_kv_fetch_statically_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_kv_fetch_statically.Click

    End Sub

    Private Sub unqlite_kv_fetch_callback_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_kv_fetch_callback.Click

    End Sub

    Private Sub unqlite_kv_delete_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_kv_delete.Click

    End Sub

    Private Sub unqlite_kv_config_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_kv_config.Click

    End Sub

#End Region

    
End Class
