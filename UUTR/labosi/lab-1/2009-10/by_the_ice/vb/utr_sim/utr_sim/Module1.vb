Module Module1

    Sub Main()
        Dim strDef As String
        Dim strSim As String
        Dim curState As String
        Dim strTmp() As String
        Dim strTmp2() As String
        Dim cAutomat As Hashtable
        cAutomat = New Hashtable

        curState = "POCETAK"
        strDef = IO.File.ReadAllText("def.txt")
        strTmp = Split(strDef, vbCrLf)
        For i = 0 To UBound(strTmp)
            If strTmp(i) <> "" Then
                strTmp2 = Split(strTmp(i), " ")
                If UBound(strTmp2) = 2 Then
                    cAutomat.Add(strTmp2(0) & " " & strTmp2(1), strTmp2(2))
                End If
            End If
        Next

        strSim = IO.File.ReadAllText("sim.txt")
        strTmp = Split(strSim, " ")
        For i = 0 To UBound(strTmp)
            If cAutomat.ContainsKey(curState & " " & strTmp(i)) = False Then
                Console.WriteLine("Niz se ne prihvaca")
                Console.ReadKey()
                End
            End If
            curState = cAutomat(curState & " " & strTmp(i))
        Next
        If InStr(curState, ",") Then
            Console.WriteLine("Niz se ne prihvaca")
            Console.ReadKey()
            End
        End If
        Console.Write("Niz se prihvaca")
        Console.ReadKey()
    End Sub

End Module
