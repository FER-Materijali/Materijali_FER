Module Module1
    Private Structure Site 'struktura za spremanje informacija o stranicama
        Dim strName As String 'ime stranice (eg www.vecernji.hr)
        Dim strLink As String 'linkovi na druge stranice
        Dim strRes As String 'resursi (img1, img2...)
    End Structure
    Sub Main()
        Dim oRead As System.IO.StreamReader 'stream za citanje datoteke
        Dim oWrite As System.IO.StreamWriter 'za pisanje datoteke
        Dim strLine As String 'string u koji ucitavanje linije
        Dim strTmp() As String 'privremena varijabla
        Dim strTmp2() As String 'privremena varijabla
        Dim stSites As Site() 'lista stranica
        Dim cAutomat As Hashtable 'mapa
        Dim cState As Collection 'dinamicka lista

        ReDim stSites(0)
        cAutomat = New Hashtable
        cState = New Collection

        oRead = IO.File.OpenText("input.txt")
        While (oRead.EndOfStream = False)  'do kraja datoteke ucitavaj
            strLine = oRead.ReadLine 'ucitaj jednu liniju
            strTmp = Split(strLine, "|") 'podijelu ucitanu liniju po znaku |
            strTmp2 = Split(strTmp(0), ":")
            ReDim Preserve stSites(UBound(stSites) + 1)
            With stSites(strTmp2(0)) ' strTmp2(0) - index stranice (broj)
                .strName = strTmp2(1)
                .strLink = strTmp(1)
                .strRes = strTmp(2)
            End With
            'Console.WriteLine(strLine)
        End While
        With stSites(0) 'dodaj linkove na sve druge stranice
            .strName = "POCETAK"
            For i = 1 To UBound(stSites) - 1
                .strLink = .strLink & i & ","
            Next
            .strLink = .strLink & UBound(stSites)
        End With
        For i = 0 To UBound(stSites)
            strTmp = Split(stSites(i).strLink, ",") 'za sve linkove
            For j = 0 To UBound(strTmp)
                'strTmp(j) - index stranice na koju link vodi
                ' stSites(strTmp(j)).strName - ime stranice (www.index.hr) na koju link vodi
                cAutomat.Add(stSites(i).strName & " " & stSites(strTmp(j)).strName, stSites(strTmp(j)).strName & "," & stSites(strTmp(j)).strRes)
                cState.Add(stSites(strTmp(j)).strName & "," & stSites(strTmp(j)).strRes)
            Next
        Next
        Dim it As Integer = 1
        While cState.Count >= it 'za sva stranja koja moramo obraditi
            strTmp = Split(cState(it), ",") 'podijelimo stanje (www.vecernji.hr,img1,img2) na dijelove
            For j = 1 To UBound(strTmp) 'za svaki resurs
                If cAutomat.ContainsKey(cState(it) & " " & strTmp(j)) = False Then
                    cAutomat.Add(cState(it) & " " & strTmp(j), Replace(cState(it), "," & strTmp(j), ""))
                    cState.Add(Replace(cState(it), "," & strTmp(j), ""))
                End If
            Next
            it = it + 1
        End While

        oWrite = IO.File.CreateText("def.txt")
        For i = 0 To cAutomat.Keys.Count
            Console.WriteLine(cAutomat.Keys(i) & " " & cAutomat.Values(i))
            oWrite.WriteLine(cAutomat.Keys(i) & " " & cAutomat.Values(i))
        Next
        oWrite.Close()
        Console.Read()
    End Sub

End Module
