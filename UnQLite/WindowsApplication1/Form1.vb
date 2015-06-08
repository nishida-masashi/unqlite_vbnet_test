Public Class Form1

    Private Sub unqlite_open_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_open.Click
        unqliteSample.smp_unqlite_open(RichTextBox1)
    End Sub

    Private Sub unqlite_config_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_config.Click
        unqliteSample.smp_unqlite_config(RichTextBox1)
    End Sub

    Private Sub unqlite_close_Click(sender As System.Object, e As System.EventArgs) Handles unqlite_close.Click
        unqliteSample.smp_unqlite_close(RichTextBox1)
    End Sub

End Class
