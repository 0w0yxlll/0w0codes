#define i64 long long

//eΪ�ڽӾ���nΪ��ĸ�����xΪ��ǰԴ��ı�� 
	
void mat_init(){
	//�ڽӾ����ʼ�� 
	for(i64 i=1;i<=n;i++)
		for(i64 j=1;j<=n;j++){
			e[i][j]=inf;
			if(i==j) e[i][j]=0;
		}
	return ;
}

void odr_init(i64 x){
	//dis��book�����ʼ��	
	for(i64 i=1;i<=n;i++){
		dis[i]=e[x][i];
		book[i]=0;
	}
	return ;
}
	
void init(i64 x){
	//ǿ����һ�� 
	mat_init();
	get_index(); //�������롢��ֵ 
	odr_init(x);
	return ;
}

void Dcore(i64 x){
	//���Ĳ���
	book[x]=1;
	for(i64 k=1;k<=n-1;k++){
		i64 u,mind=inf;
		//������ĵ�
		for(i64 i=1;i<=n;i++){
			if(book[i]==0&&mind>dis[i]){
				mind=dis[i];
				u=i;
			}
		}
		//�Դ˵�Ϊ������չ
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
