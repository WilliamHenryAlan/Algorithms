

//ACM模式下要处理多组数据 模板：

// C language
while (scanf("%d %d") != EOF) { //EOF是预定义量 = -1 
	...
}
//scanf返回读取数据个数 所以也可以写成
while (scanf("%d %d") != 2) { 
	...
}
// C++ language
while (cin >> a >> b) {
	...
}
