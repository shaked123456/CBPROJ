object MessProcessFr: TMessProcessFr
  Left = 0
  Top = 0
  Width = 366
  Height = 388
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 366
    Height = 388
    Align = alClient
    Caption = 'Action'
    TabOrder = 0
    DesignSize = (
      366
      388)
    object Label11: TLabel
      Left = 27
      Top = 72
      Width = 57
      Height = 13
      Caption = 'Text format'
    end
    object Label2: TLabel
      Left = 27
      Top = 174
      Width = 50
      Height = 13
      Caption = 'Play count'
    end
    object SelWavCommonButton: TSpeedButton
      Left = 334
      Top = 137
      Width = 25
      Height = 25
      Hint = 'Select wav file'
      Flat = True
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        1800000000000003000000000000000000000000000000000000000000000000
        000000000000000000036496036393035F8E0000000000000000000000000000
        00000000000000000000000000000000000000036CA2036BA01F80B054A8D00A
        5A7D35350F35350F35350F35350F35350F35350F35350F383812000000000000
        0364953795C369BADF81CBEC84CEEE4A8FB1FFFFFFFFFFFEFEFEFDFEFEFCFDFD
        FAFCFCF9FEFEF94F4F28000000000000036DA287D1EF7FCAE97FCAE987D0EF4D
        92B5C29154AA6815D9B990FBFBF8FAFAF6F8F8F4FBFBF6696941000000000000
        0377B18AD3F082CDEB82CDEB8AD3F05095B8D58E34F0B04DD3892AFAFAF6F8F8
        F4F7F7F1FAFAF472724A000000000000027BB88ED6F287D0ED87D0ED8ED6F252
        98BBFBE7CCF9D09CFBA842FADBB2F9E0BDF5F5EFFAFAF2797951000000000000
        027EBC92DAF48BD4F08BD4F092DAF4559BBFFBFBF8FAFAF6FF942DF8EEDEFE9E
        42F4F4ECF9F9EF8181590000000000000281C097DEF690D8F290D8F297DEF659
        9EC2FAFAF6F8F8F4F77A14F5EFE4F78222F0F0E6F6F6E8888860000000000000
        0284C49BE1F794DBF494DBF49BE1F75BA2C5F8F8F4F7F7F1FB9E38E3A455F6BD
        7BEBEBDDF4F4E38F8F660000000000000286C89EE5F998DFF698DFF69EE5F95E
        A5C8F7F7F1F5F5EFFFBB55FDC36AECE8D6E7E7D6F2F2E196966D000000000000
        0289CCA3E8FB9DE3F99DE3F9A3E8FB62A9CAF5F5EFF4F4ECFFBB55EDE3C8B5B5
        A4B5B5A4B5B5A45D5D35000000000000028BD0A6EBFCA1E6FBA1E6FBA6EBFC6A
        B1D2F4F4ECF0F0E6EBEBDDE7E7D6C7C7B6FFFFFFA1A177A1A177000000000000
        028DD3A9EEFDA4E9FCA4E9FCAAEEFD74B6D4F8F8EEF6F6E8F3F3E3F2F2E1D3D3
        C2609BA1A5A57C000000000000000000028FD6ACF1FFABEFFE98E6FA77D2F254
        A9C7A8D1CBA8D1CBA8D1CBA8D1CBABD4CC2795C4000000000000000000000000
        0291D98DE1F86ACCF16BCDF18CDFF8A8EFFEAEF2FFAEF2FFAEF2FFAEF2FFB1F5
        FF0291D90000000000000000000000000292DB0292DB0292DB0292DB0292DB02
        92DB0292DB0292DB0292DB0292DB0292DB0292DB000000000000}
      ParentShowHint = False
      ShowHint = True
      OnClick = SelWavCommonButtonClick
    end
    object PlayButton: TSpeedButton
      Left = 148
      Top = 114
      Width = 25
      Height = 25
      Hint = 'Play selected file'
      Anchors = [akTop, akRight]
      Flat = True
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000E18F2500E18F
        2500DF9129E2C3770000E18F2500E18F2500E18F2500E18F2500E18F2500E18F
        2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F
        2500E19026FBE09026FFD78819DFC87E0500E18F2500E18F2500E18F2500E18F
        2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F
        2500E29126F6F0B32EFFE79E29FCE18F25FFDA8C1CE0D48B1100E18F2500E18F
        2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F
        2500E29125F6F7B92BFFF6B82BFFF2B52DFFE79F29FCE19025FFDE911FE2DD94
        1A00E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F
        2500E29126F6F9C03CFFFBC13CFFFAC03CFFF7BE3CFFF4BB3CFFE9A22FFEE292
        26FFE19423E7E2992000E18F2500E18F2500E18F2500E18F2500E18F2500E18F
        2500E29227F6FBC956FFFDCC58FFFDCC58FFFCCB57FFFBC956FFF9C654FFF5C3
        51FFEDAE40FFE39529FFE39626EBE49A2400E18F2500E18F2500E18F2500E18F
        2500E29228F6FCD16EFFFED572FFFED572FFFED572FFFED572FFFDD471FFFCD2
        6FFFFACF6BFFF7CA65FFEEB54EFFE49A2FFDE1902600E18F2500E18F2500E18F
        2500E29229F6FCE085FFFFE58BFFFFE58BFFFFE58BFFFFE58BFFFFE58BFFFFE5
        8BFFFFE48AFFFDE186FFF9DA7CFFECB551FFE39429AEE18F2500E18F2500E18F
        2500E2932AF6FCEB95FFFFF19DFFFFF19DFFFFF19DFFFFF19DFFFFF19DFFFFF1
        9DFFFEEF9AFFFCEA94FFF2CC6EFFE49B33EFE1902600E18F2500E18F2500E18F
        2500E2932AF6FCEEA7FFFFF4B0FFFFF4B0FFFFF4B0FFFFF4B0FFFEF2ADFFFCED
        A6FFF5D684FFE6A23EF0E2942CD2E18F2500E18F2500E18F2500E18F2500E18F
        2500E2932BF6FCEFADFFFFF5B7FFFFF5B7FFFEF3B5FFFDEFAEFFF7DC91FFE7A6
        45F1E2942CE0E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F
        2500E2932BF6FCEFB3FFFFF5BCFFFDF0B5FFF8E19CFFE8AA4CF3E2932AECE18F
        2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F
        2500E2932BF6FBECB1FFF9E7AAFFE9AF53F5E29229F2E1912700E18F2500E18F
        2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F
        2500E2932BF6EAB158F8E19026FBE2922900E18F2500E18F2500E18F2500E18F
        2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F
        2500E2942DCFE2922A00E18F2507E18F2500E18F2500E18F2500E18F2500E18F
        2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F
        2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F
        2500E18F2500E18F2500E18F2500E18F2500E18F2500E18F2500}
      ParentShowHint = False
      ShowHint = True
      OnClick = PlayButtonClick
    end
    object SpeedButton1: TSpeedButton
      Left = 334
      Top = 279
      Width = 25
      Height = 25
      Hint = 'Select program'
      Flat = True
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000300000
        0033000000330000003300000033000000330000003300000033000000330000
        00330000003300000033000000330000002F00000000000000004598D1F24398
        D2FF4094D0FF3E92CFFF3E92CEFF3F92CEFF3F92CEFF3F92CEFF3F92CEFF3F92
        CEFF3F92CEFF3F92CEFF3F93CFFF4194CEF00000000E000000004499D2FF3F94
        D0FFABFBFFFF9BF3FFFF92F1FFFF93F1FFFF93F1FFFF93F1FFFF93F1FFFF93F1
        FFFF93F1FFFF93F1FFFFA6F8FFFF65B8E3FF31709D5F000000004398D2FF4FA6
        D9FF8EDAF5FFA2EEFFFF82E5FEFF84E5FEFF84E5FEFF85E6FEFF85E6FEFF85E6
        FEFF85E6FEFF84E6FEFF96EBFFFF8CD8F5FF3985BCB8000000004296D1FF6BBE
        E8FF6DBDE6FFBBF2FFFF75DEFDFF77DEFCFF78DEFCFF7BDFFCFF7DDFFCFF7DDF
        FCFF7DDFFCFF7CDFFCFF80E0FDFFADF0FFFF4D9DD3FF0000000E4095D0FF8AD7
        F5FF44A1D8FFDDFDFFFFDAFAFFFFDBFAFFFFDEFAFFFF74DCFCFF76DBFAFF75DA
        FAFF74DAFAFF74DAFAFF72D9FAFFA1E8FFFF7CBFE6FF306F9C5E3E94D0FFABF0
        FFFF449DD6FF368CCBFF368CCBFF368CCBFF378BCBFF5CBEEAFF6FD9FBFF6AD6
        FAFF68D5F9FF67D4F9FF66D4F9FF82DEFCFFAAE0F6FF3885BCB93D92CFFFB9F4
        FFFF73DBFBFF6BCCF2FF6CCDF3FF6CCEF3FF6DCEF3FF479CD4FF56BAE9FFDAF8
        FFFFD7F6FFFFD6F6FFFFD5F6FFFFD5F7FFFFDBFCFFFF3E94D0FF3C92CFFFC0F3
        FFFF71DAFBFF74DBFBFF75DBFCFF75DBFCFF76DCFCFF73DAFAFF449CD4FF378C
        CBFF368CCBFF358CCCFF348DCCFF3890CEFF3D94D0FF4398D2EB3B92CFFFCAF6
        FFFF69D5F9FF6CD5F9FF6BD5F9FF69D5F9FF69D5FAFF6AD7FBFF68D4FAFF5EC7
        F1FF5EC7F2FF5DC8F2FFB4E3F8FF3D94D0FF3F8FC669000000003B92CFFFD5F7
        FFFF60D1F9FF61D0F8FFB4EBFDFFD9F6FFFFDAF8FFFFDAF8FFFFDBF9FFFFDCFA
        FFFFDCFAFFFFDCFBFFFFE0FFFFFF3E95D0FF4599D333000000003D94D0FFDCFC
        FFFFD8F7FFFFD8F7FFFFDBFAFFFF358ECDFF3991CEFF3A92CFFF3A92CFFF3A92
        CFFF3A92CFFF3B92CFFF3D94D0FF4398D2D700000000000000004398D2B03D94
        D0FF3A92CFFF3A92CFFF3D94D0FF4197D1D20000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000}
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton1Click
    end
    object InsertProgramButton: TSpeedButton
      Tag = 1
      Left = 307
      Top = 252
      Width = 25
      Height = 25
      Hint = 'Insert...'
      Flat = True
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000000000000000
        000000000000000000000000000000000000000000000FC68F380FC68FFF0FC6
        8F38000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000FC68F3811C48EFFFFFFFFFF11C4
        8EFF0FC68F380000000000000000000000000000000000000000000000000000
        00000000000000000000000000000FC68F3813C28CFF85F7D5FF0FE3AFFF85F7
        D5FF12C28CFF0FC68F3800000000000000000000000000000000000000000000
        000000000000000000000FC68F3815C08AFF78F5D1FF10E1ADFF0FE2ADFF0FE2
        ADFF78F5D1FF15C08AFF0FC68F38000000000000000000000000000000000000
        0000000000000FC68F3818BD88FF55EDC4FF0FE0ABFF0FDFABFF0FE0ABFF0FDF
        ABFF0FE0ABFF55EDC4FF18BD88FF0FC68F380000000000000000000000000000
        00000FC68F381BB985FF3BE7B9FF0FDDA9FF0FDCA9FF0FDDA9FF0FDDA9FF0FDD
        A9FF0FDCA8FF0EDDA8FF3BE7B9FF1BB985FF0FC68F3800000000000000000FC6
        8F381EB783FF30E2B3FF2CE1B1FF2BE1B1FF0FDAA6FF0FDAA6FF0EDAA6FF0FDA
        A6FF0EDBA6FF2CE1B1FF2CE1B1FF30E2B3FF1EB783FF0FC68F380000000021B3
        80FF21B380FF22B380FF22B380FF22B380FF0ED7A3FF0ED8A3FF0ED7A4FF0ED8
        A3FF0FD8A3FF21B380FF22B380FF22B380FF21B380FF22B380FF000000000000
        000000000000000000000000000025B07EFF0ED29FFF0ED5A1FF0ED5A1FF0ED6
        A1FF0DD29EFF24B07DFF00000000000000000000000000000000000000000000
        000000000000000000000000000028AC7BFF0FCC9AFF0DD39EFF0DD39EFF0ED3
        9EFF0FCD9AFF28AD7BFF00000000000000000000000000000000000000000000
        00000000000000000000000000002BA978FF0FC895FF0DD19CFF0DD09BFF0DD0
        9CFF0FC795FF2BA979FF00000000000000000000000000000000000000000000
        00000000000000000000000000002EA776FF0FC392FF0DCE99FF0DCE99FF0DCE
        9AFF0FC392FF2EA776FF00000000000000000000000000000000000000000000
        000000000000000000000000000030A474FF10C190FF10C190FF10C190FF10C0
        90FF10C190FF30A474FF00000000000000000000000000000000000000000000
        000000000000000000000000000032A173FF3DD7A8FF3DD7A8FF3DD7A8FF3DD7
        A8FF3DD7A8FF32A172FF00000000000000000000000000000000000000000000
        000000000000000000000000000034A071FF34A071FF34A071FF34A071FF34A0
        71FF34A071FF34A071FF00000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000}
      ParentShowHint = False
      ShowHint = True
      OnClick = InsertProgramButtonClick
    end
    object InsertAlarmMessButton: TSpeedButton
      Tag = 1
      Left = 307
      Top = 60
      Width = 25
      Height = 25
      Hint = 'Insert...'
      Flat = True
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000000000000000
        000000000000000000000000000000000000000000000FC68F380FC68FFF0FC6
        8F38000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000FC68F3811C48EFFFFFFFFFF11C4
        8EFF0FC68F380000000000000000000000000000000000000000000000000000
        00000000000000000000000000000FC68F3813C28CFF85F7D5FF0FE3AFFF85F7
        D5FF12C28CFF0FC68F3800000000000000000000000000000000000000000000
        000000000000000000000FC68F3815C08AFF78F5D1FF10E1ADFF0FE2ADFF0FE2
        ADFF78F5D1FF15C08AFF0FC68F38000000000000000000000000000000000000
        0000000000000FC68F3818BD88FF55EDC4FF0FE0ABFF0FDFABFF0FE0ABFF0FDF
        ABFF0FE0ABFF55EDC4FF18BD88FF0FC68F380000000000000000000000000000
        00000FC68F381BB985FF3BE7B9FF0FDDA9FF0FDCA9FF0FDDA9FF0FDDA9FF0FDD
        A9FF0FDCA8FF0EDDA8FF3BE7B9FF1BB985FF0FC68F3800000000000000000FC6
        8F381EB783FF30E2B3FF2CE1B1FF2BE1B1FF0FDAA6FF0FDAA6FF0EDAA6FF0FDA
        A6FF0EDBA6FF2CE1B1FF2CE1B1FF30E2B3FF1EB783FF0FC68F380000000021B3
        80FF21B380FF22B380FF22B380FF22B380FF0ED7A3FF0ED8A3FF0ED7A4FF0ED8
        A3FF0FD8A3FF21B380FF22B380FF22B380FF21B380FF22B380FF000000000000
        000000000000000000000000000025B07EFF0ED29FFF0ED5A1FF0ED5A1FF0ED6
        A1FF0DD29EFF24B07DFF00000000000000000000000000000000000000000000
        000000000000000000000000000028AC7BFF0FCC9AFF0DD39EFF0DD39EFF0ED3
        9EFF0FCD9AFF28AD7BFF00000000000000000000000000000000000000000000
        00000000000000000000000000002BA978FF0FC895FF0DD19CFF0DD09BFF0DD0
        9CFF0FC795FF2BA979FF00000000000000000000000000000000000000000000
        00000000000000000000000000002EA776FF0FC392FF0DCE99FF0DCE99FF0DCE
        9AFF0FC392FF2EA776FF00000000000000000000000000000000000000000000
        000000000000000000000000000030A474FF10C190FF10C190FF10C190FF10C0
        90FF10C190FF30A474FF00000000000000000000000000000000000000000000
        000000000000000000000000000032A173FF3DD7A8FF3DD7A8FF3DD7A8FF3DD7
        A8FF3DD7A8FF32A172FF00000000000000000000000000000000000000000000
        000000000000000000000000000034A071FF34A071FF34A071FF34A071FF34A0
        71FF34A071FF34A071FF00000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000}
      ParentShowHint = False
      ShowHint = True
      OnClick = InsertAlarmMessButtonClick
    end
    object SpeedButton2: TSpeedButton
      Left = 334
      Top = 354
      Width = 25
      Height = 25
      Hint = 'Add new file'
      Flat = True
      Glyph.Data = {
        36050000424D3605000000000000360400002800000010000000100000000100
        0800000000000001000000000000000000000001000000000000DE9A3E00DA9A
        4400D89C4B00D3A05A00E6A65400E6A85700E6AA5A00E6AB5B00E6AD5D00CEA3
        6A00D0A26200D1A26300E8AF6100E6B06700E8B06200EDB16700E6B16800E6B2
        6B00EDB56C00EEB46C00E8B67000E8B77300EDB77000EEB77000EDBA7300EFB9
        7400EDBB7400EDBB7500EEBF7C00EDC07C00EDBF8100EDC48800EDC48A00EDC6
        8C00F4C38400F4C78900F2CB8F00EEC89200F8CA9000FCCB9500F8CF9600FCCC
        9600F2CD9900F0CE9D00FECF9D00FECF9E00F2D49C00F6D59F00F2D6A500FBD6
        A300F6DBA700F5D7AB00FBD9A800FBDBAB00FDD9A800FDDAAA00FEDAAA00FCDC
        AB00FBDAAC00F6DBB300F6DCB400FDDEB000FAE0B100FAE0B700FAE3B600FDE2
        B600FBE4B600FBE4BB00FFE4B900FCE6B900FDE6BA00F9E1BD00FEE7BD00C0C0
        C000FAE5C400FAE6C700FAEDC300FAEACB00FFEACB00FAEECA00FDEACE00FFF3
        CE00FCEBD100FCEDD400FFEDD400FDF0D600FEF2DE00FEF3DE00FFF3DE00FFFC
        DA00FEF6E700FFF8E300FFFDE600FFFCF3000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000002802000000000000000000000000
        00000000000000000000000000000000000047CC000028118C0000000500DC15
        8C0018EE9000C0409100FFFFFF00BB4091008ED60100450000001C138C008000
        1000DC158C0018EE900070059100FFFFFF00000000003D04910050148C00750B
        8100000000000100000002000000CC158C00180000000000000038148C004200
        0000000000001C148C000000000000000000000000000C000000020000000101
        900000ECFD004E000000000000000200000056001A00E05D0B0000000000E05D
        0B0005000000DFE2800074148C004F1A80002C01000000000000000000000000
        0000020000008000000000000000B4158C00AFD44A00B085F700000000000000
        0000A8158C00020000008000000000000000000100003C168C0031C5D400443A
        5C004F524B004C4D50006F6A6500745C6900616765005C3136006F7074006F6E
        7300626D700000000000E0148C0000000000C805910068AC4200AC158C005105
        9100F8148C0000000000C8059100E8E307000700000051059100D80705006D05
        9100070000000400000000000000757E4A003800000054041100020000002000
        000000000000D80BF7000987D4005404110038000000E0900000000038003C13
        8C003800000088158C0018EE9000F0069100FFFF010007000000BC148C000000
        3800B0158C0018EE900070059100FFFFFF006D059100E7D34800000038000000
        0000D80BF7000000000008168C0031C5D4006020F50098130500000000000000
        01000C00000000000000010000000F000000D6044600B085F700494949494949
        4949494949494949494949494949494900000049494949494949494949094949
        08480849490A494949494949010701021C391A02010E01494949490A0C38231D
        424635182837060949494949012645594C323E443622014949494949021B512E
        0003002444160249494900040F344000494949003E3113040049002D293D2F03
        494949033241272C00490017193A3F00494949004F43120500494949021E4E2A
        000300305C1F024949494949013350544A3C4D5B55470149494949090D584B20
        525653213B57140A4949494901150102255A2B020110014949494949490B4949
        115D114949094949494949494949494900000049494949494949}
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton2Click
    end
    object IgnoreCB: TCheckBox
      Left = 11
      Top = 24
      Width = 334
      Height = 17
      Hint = 
        'By default, all messages are written to the default file "syslog' +
        '"'
      Caption = 'Ignore (do not save to the default file "syslog")'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = Change
    end
    object AlarmCB: TCheckBox
      Left = 11
      Top = 47
      Width = 182
      Height = 17
      Caption = 'Show alarms window'
      TabOrder = 1
      OnClick = Change
    end
    object AlarmMessEdit: TEdit
      Left = 27
      Top = 91
      Width = 305
      Height = 21
      TabOrder = 2
      OnChange = Change
    end
    object SoundCB: TCheckBox
      Left = 11
      Top = 118
      Width = 118
      Height = 17
      Caption = 'Play sound file'
      TabOrder = 3
      OnClick = Change
    end
    object SoundFileEdit: TEdit
      Left = 27
      Top = 141
      Width = 305
      Height = 21
      TabOrder = 4
      OnChange = Change
    end
    object PlayCountEdit: TEdit
      Left = 100
      Top = 170
      Width = 57
      Height = 21
      Hint = 'Closing alarms window stop playing sound'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      OnChange = Change
    end
    object SendMailCB: TCheckBox
      Left = 11
      Top = 197
      Width = 118
      Height = 17
      Caption = 'Send e-mail to'
      TabOrder = 6
      OnClick = Change
    end
    object RunProgCB: TCheckBox
      Left = 11
      Top = 260
      Width = 153
      Height = 17
      Caption = 'Run external program'
      TabOrder = 8
      OnClick = Change
    end
    object ProgFileEdit: TEdit
      Left = 27
      Top = 283
      Width = 305
      Height = 21
      TabOrder = 9
      OnChange = Change
    end
    object ProgHideCB: TCheckBox
      Left = 27
      Top = 310
      Width = 153
      Height = 17
      Caption = 'Hide program windows'
      TabOrder = 10
      OnClick = Change
    end
    object SaveToFileCB: TCheckBox
      Left = 11
      Top = 333
      Width = 153
      Height = 17
      Caption = 'Save to file'
      TabOrder = 11
      OnClick = Change
    end
    object RecipientEdit: TEdit
      Left = 27
      Top = 220
      Width = 305
      Height = 21
      TabOrder = 7
      OnChange = Change
      OnEnter = RecipientEditEnter
      OnExit = RecipientEditExit
    end
    object SaveFileCB: TComboBox
      Left = 23
      Top = 356
      Width = 305
      Height = 21
      Style = csDropDownList
      DropDownCount = 20
      ItemHeight = 13
      TabOrder = 12
      OnSelect = Change
    end
  end
  object InsertPopupMenu: TPopupMenu
    Left = 296
    Top = 8
    object time1: TMenuItem
      Caption = '{time}'
      OnClick = pmInsertClick
    end
    object ip1: TMenuItem
      Tag = 1
      Caption = '{ip}'
      OnClick = pmInsertClick
    end
    object host1: TMenuItem
      Tag = 2
      Caption = '{host}'
      OnClick = pmInsertClick
    end
    object facility1: TMenuItem
      Tag = 3
      Caption = '{facility}'
      OnClick = pmInsertClick
    end
    object priority1: TMenuItem
      Tag = 4
      Caption = '{priority}'
      OnClick = pmInsertClick
    end
    object tag1: TMenuItem
      Tag = 5
      Caption = '{tag}'
      OnClick = pmInsertClick
    end
    object message1: TMenuItem
      Tag = 6
      Caption = '{message}'
      OnClick = pmInsertClick
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'wav'
    Filter = 'All files (*.*)|*.*'
    Options = [ofNoChangeDir, ofEnableSizing]
    Left = 332
    Top = 11
  end
end
