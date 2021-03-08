**lua gc原理**

* 三色标记法

**协程**

- 协程（coroutine），意思就是协作的例程，最早由Melvin Conway在1963年提出并实现。跟主流程序语言中的线程不一样，线程属于侵入式组件，线程实现的系统称之为抢占式多任务系统，而协程实现的多任务系统成为协作式多任务系统。线程由于缺乏yield语义，所以运行过程中不可避免需要调度，休眠挂起，上下文切换等系统开销，还需要小心使用同步机制保证多线程正常运行。而协程的运行指令系列是固定的，不需要同步机制，协程之间切换也只涉及到控制权的交换，相比较线程来说是非常轻便的。不过同一时刻可以有多个线程运行，但却只能有一个协程运行。
- 协程具有两个非常重要的特性：
  - 私有数据在协程的间断式运行期间一直有效
  - 协程每次yield后让出控制权，下次被resume后从停止点开始继续执行
- resume／yield语义实现的协程属于非对称协程 A resume B resume C， C yield只能到B，而不能到A或其他协程
- 对称协程只有一个语义可以将控制流直接转到目的协程

**数据类型**

* nil, boolean, number, string, userdata, function, thread, table

**pairs 和 ipairs区别**

* pairs: 迭代 table，可以遍历表中所有的 key 可以返回 nil
* ipairs: 迭代数组，不能返回 nil,如果遇到 nil 则退出

**闭包**

* 闭包组成：外部函数+外部函数创建的upvalue+内部函数

**string api**

*  **table.concat**, 效率比 .. 高
* **string.gsub(mainString,findString,replaceString,num)**
* **string.find (str, substr, [init, [end]])**

**lua只读表**

```lua
--禁止赋新值
__newindex = function() 
    assert(false, 'table is readonly\n') 
end

--禁止修改值
local readonly = function(t)
    local meta = {
        __index    = t,
        __newindex = function() assert(false, 'table is readonly\n') end,
    }
    local locked = {}
    setmetatable(locked, meta)
    return locked
end


local static = {
    exist={exist={exist=true}},
}
static = readonly(static)
static['exist'] = false

--子表也设为只读
local static = {
    exist={exist={exist=true}},
}

local readonly
readonly = function(t, deep)
    if deep then
        for k,v in pairs(t) do
            if type(v) == 'table' then
                t[k] = readonly(v, deep)
            end
        end
    end

    local meta = {
        __index    = t,
        __newindex = function() assert(false, 'table is readonly\n') end,
    }
    local locked = {}
    setmetatable(locked, meta)
    return locked
end

static = readonly(static, true)
static['exist']['exist']['exist'] = false
```

