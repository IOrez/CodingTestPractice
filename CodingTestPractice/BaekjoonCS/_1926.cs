using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekjoonCS
{
    internal class _1926
    {
        int row, col;
        int[,] table;
        bool[,] check;
        private void Init()
        {
            String[] rowcol = Console.ReadLine().Split(' ');
            row = Convert.ToInt32(rowcol[0]);
            col = Convert.ToInt32(rowcol[1]);
        
            table = new int[row,col];
            check = new bool[row, col];

            for(int i = 0; i < row; i++)
            {
                String[] strings = Console.ReadLine().Split(' ');
                for (int j = 0; j < col; j++)
                {
                    table[i,j] = Convert.ToInt32(strings[j]);
                }
            }
        }

        private class Data
        {
            public int x;
            public int y;

            public Data(int y, int x) { this.x = x; this.y = y; }
        }

        public void Solution()
        {
            Init();
            Queue<Data> que = new Queue<Data>();
            int maxCount = 0, count = 0, group = 0;
            for(int i = 0; i < row; i ++)
            {
                for(int j = 0; j < col; j++)
                {
                    if (check[i, j] == true || table[i, j] == 0)
                        continue;

                    group++;
                    que.Enqueue(new Data(i, j));
                    check[i, j] = true;
                    count = 1;
                    int[] dx = new int[]{ -1, 1, 0, 0 };
                    int[] dy = new int[] { 0, 0, 1, -1 };
                    while(que.Count != 0)
                    {
                        Data data = que.Dequeue();
                        for(int k = 0; k < 4; k++)
                        {
                            int xx = data.x + dx[k], yy = data.y + dy[k];
                            if (xx < 0 || xx >= col || yy < 0 || yy >= row)
                                continue;

                            if (table[yy, xx] == 0 || check[yy,xx] == true)
                                continue;

                            check[yy, xx] = true;
                            count++;

                            que.Enqueue(new Data(yy, xx));
                        }
                    }
                    maxCount = Math.Max(maxCount, count);
                }
            }
            Console.WriteLine(group.ToString());
            Console.WriteLine(maxCount.ToString());
            Console.ReadLine();
        }
    }
}
