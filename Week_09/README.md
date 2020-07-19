学习笔记
不同路径2状态方程
if graph[i][j] = 0
	dp[i][j] = 0;
if graph[i][j] != 0
	dp[i][j] = dp[i-1][j] + dp[i][j-1]