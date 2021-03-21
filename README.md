# MingjieC

明解C语言代码、习题练习

!!! 注意：使用POSIX标准的编译器会定义宏CLOCKS_PER_SEC的值为1000000也就是1000^2，而作者所用的编译器认为CLOCKS_PER_SEC为1000，这就导致作者的很多示例代码在UNIX-like的机子上是无法得到正常的结果。

由于macOS和Windows对于time()函数的区别（具体看这里：https://stackoverflow.com/questions/27178789/c-different-implementation-of-clock-in-windows-and-other-os）
，很多用来计时的代码块是不合适在UNIX-like的系统上运行的，办法，等我把这些代码弄完再去想吧（头疼）

具体想法思路应该会写在每一个练习之后的readme里面（现在还没有）

还有很多没仔细思考只是蒙过的点，需要回头好好看看。

不过整体看下来这本书并没有很系统的讲解C语言里面的知识（想系统看的话还是要去看C primer plus之类的大部头）

反正预计这周会把练习写完（如果写不完那就  写不完了）
