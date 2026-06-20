'[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_init.Inc
'-----------------------------------------------------------------------------
' 由 VisualFreeBasic 5.9.8 生成的源代码
' 生成时间：2026年03月21日 20时16分03秒
' 更多信息请访问 www.yfvb.com 
'-----------------------------------------------------------------------------



' DimP 符号对(...) As ZString*12 = {"符号对{xx}","中“”", """", "中‘’", "''", "中《》", "<>", "中【】", "[]", "中「」", "{}", "中（）", "()"} '已经搬到定义文件处

'初始化符号对
Sub Init_CH_E7ACA6E58FB7E5AFB9_()
   Dim i As Integer 
   For i = 0 To UBound(CH_E7ACA6E58FB7E5AFB9_)
      Form1.Combo_CH_E7ACA6E58FB7E5AFB9_.AddItem CH_E7ACA6E58FB7E5AFB9_(i)
   Next
   Form1.Combo_CH_E7ACA6E58FB7E5AFB9_.ListIndex = 0
End Sub
