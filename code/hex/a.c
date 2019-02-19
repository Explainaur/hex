//树类
//栈类
//队列类

    
#ifndef BOARD_SIZE
#define BOARD_SIZE 11
#define BOARD_SIZE_2 121

#ifndef DEPTH
#define DEPTH 10

//类里面添加
//存放最优落子点坐标
int optimal_a,optimal_b;
//computing_node为true计算，默认边界两格添加---
bool computing_node[BOARD_SIZE_2];
std::queue<int> computing;

//更新落子点，把已落子相邻两格的computing_node改为true
void Robot :: Increannode (int a)//落子的地址a
{
    int i,j;
    i=a/BOARD_SIZE;
    j=a%BOARD_SIZE;
    if(i>2&&i<=BOARD_SIZE-2&&j>2&&j<=BOARD_SIZE-2)//中间的点
    {
        for(int d=-2;d<3;d++)
        {   
            if(!computing_node[a+d*BOARD_SIZE]&&d!=0)
            {
                computing.push(a+d*BOARD_SIZE);
                computing_node[a+d*BOARD_SIZE]=true;
            }
            if(!computing_node[a+d*BOARD_SIZE+1])
            {
                computing.push(a+d*BOARD_SIZE+1);
                computing_node[a+d*BOARD_SIZE+1]=true;
            }
            if(!computing_node[a+d*BOARD_SIZE+2])
            {
                computing.push(a+d*BOARD_SIZE+2);
                computing_node[a+d*BOARD_SIZE+2]=true;
            }
            if(!computing_node[a+d*BOARD_SIZE-1])
            {
                computing.push(a+d*BOARD_SIZE-1);  
                computing_node[a+d*BOARD_SIZE-1]=true;   
            }
            if(!computing_node[a+d*BOARD_SIZE-2])
            {
                computing.push(a+d*BOARD_SIZE-2);
                computing_node[a+d*BOARD_SIZE-2]=true;
            }
        } 
    }
    else//四周的点
    {
        for (int ii=-2;ii<3;ii++)
        {
            if(i+ii>BOARD_SIZE&&i+ii<1)
                continue;
            for (int jj=-2;jj<3;jj++)
            {
                if (j+jj>BOARD_SIZE&&j+jj<1||ii==0&&jj==0)
                    continue;
                if(!computing_node[a+ii*BOARD_SIZE+jj])
                {
                    computing.push(a+ii*BOARD_SIZE+jj);         
                    computing_node[a+ii*BOARD_SIZE+jj]=true;       
                }
            }

        } 
    }
}

//计算E值函数
int Robot :: Computing_energy ()//评价当前棋盘对手能量E
{
    
}




//剪枝算法函数
int Robot :: AlphaBeta(int h, int player, int alpha, int beta)   //h搜索深度，player=1表示自己,player=0表示对手。自己取对手E的最大值，对手取对手E的最小值。
{
    std::queue<int> ans;
    que=computing;
    if(h==DEPTH || 出现胜负 )   //若到达深度 或是出现胜负
    {
        if( 出现胜负 )
        {         
            return ;//若是胜负返回-inf 或+inf，
        }
        else
        {
            return Computing_energy ();   //返回此局面的评价值 
        }
    }
    Increannode (a,b)//标记新落子周围两格的区域

    int i, j;
    if(player==1)//自己
    {
        a=que.front;
        //把a这个点下成自己的颜色
        //更新团簇
        int ans = alpha_beta(h+1, 0, alpha, beta);
        //把a这个点置空
        if(ans > alpha)//通过向上传递的子节点beta值修正alpha值 
        {    
            alpha = ans;
            ansx = i;       //记录位置 
            ansy = j;
        }

        if(alpha >= beta)   //发生 alpha剪枝 
        {
            return alpha;
        }            
        return alpha;
    }
    else//对手
    {
        a=que.front;
        //把a这个点下成对手的颜色
        //更新团簇
        int ans = alpha_beta(h+1, 1, alpha, beta);
        //把a这个点置空
        if(ans < beta)//通过向上传递的子节点alpha值修正beta值 
        {     
            beta = ans;
            ansx = i;       //记录位置 
            ansy = j;
        }

        if(alpha >= beta)   //发生 beta剪枝
        {
            return beta;
        }
        return beta;    
    }

}



#endif 
