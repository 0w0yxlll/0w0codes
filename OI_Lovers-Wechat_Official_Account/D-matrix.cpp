#define i64 long long

//e为邻接矩阵，n为点的个数，x为当前源点的编号 
	
void mat_init(){
	//邻接矩阵初始化 
	for(i64 i=1;i<=n;i++)
		for(i64 j=1;j<=n;j++){
			e[i][j]=inf;
			if(i==j) e[i][j]=0;
		}
	return ;
}

void odr_init(i64 x){
	//dis和book数组初始化	
	for(i64 i=1;i<=n;i++){
		dis[i]=e[x][i];
		book[i]=0;
	}
	return ;
}
	
void init(i64 x){
	//强行扔一堆 
	mat_init();
	get_index(); //用来读入、赋值 
	odr_init(x);
	return ;
}

void Dcore(i64 x){
	//核心部分
	book[x]=1;
	for(i64 k=1;k<=n-1;k++){
		i64 u,mind=inf;
		//找最近的点
		for(i64 i=1;i<=n;i++){
			if(book[i]==0&&mind>dis[i]){
				mind=dis[i];
				u=i;
			}
		}
		//以此点为中心扩展
		book[u]=1;
		for(i64 i=1;i<=n;i++){
			if(book[i]==0&&dis[i]>dis[u]+e[u][i])
				dis[i]=dis[u]+e[u][i];
		}
	}
}

void Dijkstra(i64 x){
	init(x);
	Dcore(x);
} 
