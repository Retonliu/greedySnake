#ifndef MEMORY_H
#define MEMORY_H

typedef struct
{
	int key;
	int score;
}data;

bool cmp(data a, data b);
void save(int key, int score);  //保存数据
void read();  //读取数据

#endif // MEMORY_H