' ========== 测试保存功能 ==========
Sub TestSave()
    Dim i As Long
    Dim j As Long
    Dim nextId As Long

    Print "=== 测试保存功能 ==="
    
    ' ---------- 1. 准备测试数据 ----------
    Print "创建测试数据..."
    
    ' 周期任务（需要生成唯一 ID）
    nextId = 1001
    ReDim periodicTasks(2)
    
    With periodicTasks(0)
        .id = nextId : nextId = nextId + 1
        .Name = "每日锻炼"
        .createTime = Now
        .PeriodType = 1
        .currentPeriod = Now
        .nextPeriod = Now + 1
        .completed = False
        .completionCount = 0
        .onList = True
        .tempStatus = False
        ' 有 2 个子任务
        ReDim .subtasks(2, 1)
        .subtasks(0, 0) = "1"
        .subtasks(0, 1) = "2"
        .subtasks(1, 0) = "跑步"
        .subtasks(1, 1) = "0"
        .subtasks(2, 0) = "拉伸"
        .subtasks(2, 1) = "0"
    End With
    
    With periodicTasks(1)
        .id = nextId : nextId = nextId + 1
        .Name = "周会准备"
        .createTime = Now - 3
        .PeriodType = 2
        .currentPeriod = Now - 3
        .nextPeriod = Now + 4
        .completed = False
        .completionCount = 1
        .onList = True
        .tempStatus = False
        ' 无子任务
        ReDim .subtasks(0, 1)
        .subtasks(0, 0) = "0"
        .subtasks(0, 1) = "0"
    End With
    
    With periodicTasks(2)
        .id = nextId : nextId = nextId + 1
        .Name = "年度体检"
        .createTime = Now - 30
        .PeriodType = 4
        .currentPeriod = Now - 30
        .nextPeriod = Now + 335
        .completed = True
        .completionCount = 3
        .onList = False
        .tempStatus = True
        ' 有 1 个子任务
        ReDim .subtasks(1, 1)
        .subtasks(0, 0) = "1"
        .subtasks(0, 1) = "1"
        .subtasks(1, 0) = "预约医院"
        .subtasks(1, 1) = "1"
    End With

    ' 延期任务（target 存储周期任务 ID）
    ReDim deferredTasks(1)
    With deferredTasks(0)
        .name = "每日锻炼 (延期1次)"
        .createTime = Now
        .target = periodicTasks(0).id   ' 对应第一个周期任务的 ID
        .onList = True
        .tempStatus = False
        ' 无子任务
        ReDim .subtasks(0, 1)
        .subtasks(0, 0) = "0"
        .subtasks(0, 1) = "0"
    End With
    With deferredTasks(1)
        .name = "周会准备 (延期2次)"
        .createTime = Now - 2
        .target = periodicTasks(1).id   ' 对应第二个周期任务的 ID
        .onList = True
        .tempStatus = True
        ' 有 1 个子任务
        ReDim .subtasks(1, 1)
        .subtasks(0, 0) = "1"
        .subtasks(0, 1) = "1"
        .subtasks(1, 0) = "重写PPT"
        .subtasks(1, 1) = "0"
    End With

    ' 普通任务
    ReDim regularTasks(1)
    With regularTasks(0)
        .name = "交电费"
        .createTime = Now - 5
        .taskTime = Now + 2
        .onList = True
        .tempStatus = False
        ' 无子任务
        ReDim .subtasks(0, 1)
        .subtasks(0, 0) = "0"
        .subtasks(0, 1) = "0"
    End With
    With regularTasks(1)
        .name = "买生日礼物"
        .createTime = Now - 1
        .taskTime = Now + 5
        .onList = False
        .tempStatus = False
        ' 有 2 个子任务
        ReDim .subtasks(2, 1)
        .subtasks(0, 0) = "1"
        .subtasks(0, 1) = "2"
        .subtasks(1, 0) = "挑选"
        .subtasks(1, 1) = "0"
        .subtasks(2, 0) = "包装"
        .subtasks(2, 1) = "0"
    End With

    Print "原始周期任务数: " & (UBound(periodicTasks) + 1)
    Print "原始延期任务数: " & (UBound(deferredTasks) + 1)
    Print "原始普通任务数: " & (UBound(regularTasks) + 1)

    ' ---------- 2. 保存数据 ----------
    Print "正在保存数据..."
    SavePeriodicTasks()
    SaveDeferredTasks()
    SaveRegularTasks()
    Print "保存完成。"

    Print "测试保存结束。"
End Sub

' ========== 测试加载功能 ==========
Sub TestLoad()
    Dim i As Long
    Dim j As Long
    Dim taskCount As Long

    Print "=== 测试加载功能 ==="

    ' ---------- 1. 加载数据 ----------
    Print "正在加载数据..."
    LoadPeriodicTasks()
    LoadDeferredTasks()
    LoadRegularTasks()
    Print "加载完成。"

    ' ---------- 2. 显示周期任务 ----------
    taskCount = UBound(periodicTasks) + 1
    Print "周期任务数量: " & taskCount
    For i = 0 To taskCount - 1
        With periodicTasks(i)
            Print "  [" & i & "] ID=" & .id & " 名称=" & .Name
            Print "      创建时间=" & .createTime
            Print "      周期类型=" & .PeriodType
            Print "      本期=" & .currentPeriod & " 下期=" & .nextPeriod
            Print "      完成=" & .completed & " 完成次数=" & .completionCount
            Print "      上榜=" & .onList & " 临时状态=" & .tempStatus

            ' 显示子任务
            If .subtasks(0, 0) = "1" Then
                Dim subCount As Long = Val(.subtasks(0, 1))
                Print "      子任务数=" & subCount
                For j = 1 To subCount
                    Print "        子任务" & j & ": " & .subtasks(j, 0) & " 完成=" & .subtasks(j, 1)
                Next
            Else
                Print "      无子任务"
            End If
        End With
        Print
    Next

    ' ---------- 3. 显示延期任务 ----------
    taskCount = UBound(deferredTasks) + 1
    Print "延期任务数量: " & taskCount
    For i = 0 To taskCount - 1
        With deferredTasks(i)
            Print "  [" & i & "] 名称=" & .name
            Print "      创建时间=" & .createTime
            Print "      目标周期ID=" & .target
            Print "      上榜=" & .onList & " 临时状态=" & .tempStatus

            ' 显示子任务
            If .subtasks(0, 0) = "1" Then
                Dim subCount As Long = Val(.subtasks(0, 1))
                Print "      子任务数=" & subCount
                For j = 1 To subCount
                    Print "        子任务" & j & ": " & .subtasks(j, 0) & " 完成=" & .subtasks(j, 1)
                Next
            Else
                Print "      无子任务"
            End If
        End With
        Print
    Next

    ' ---------- 4. 显示普通任务 ----------
    taskCount = UBound(regularTasks) + 1
    Print "普通任务数量: " & taskCount
    For i = 0 To taskCount - 1
        With regularTasks(i)
            Print "  [" & i & "] 名称=" & .name
            Print "      创建时间=" & .createTime
            Print "      任务时间=" & .taskTime
            Print "      上榜=" & .onList & " 临时状态=" & .tempStatus

            ' 显示子任务
            If .subtasks(0, 0) = "1" Then
                Dim subCount As Long = Val(.subtasks(0, 1))
                Print "      子任务数=" & subCount
                For j = 1 To subCount
                    Print "        子任务" & j & ": " & .subtasks(j, 0) & " 完成=" & .subtasks(j, 1)
                Next
            Else
                Print "      无子任务"
            End If
        End With
        Print
    Next

    Print "测试加载结束。"
End Sub