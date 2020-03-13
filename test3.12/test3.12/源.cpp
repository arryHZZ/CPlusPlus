#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//template<class k>
//class set
//{
//	struct SetKeyOfVal
//	{
//		const k& operator()(const &val)
//		{
//			return val;
//		}
//	};
//public:
//	bool insert(const &val)
//	{
//		return _rb.insert(val);
//	}
//private:
//	RBTree<k, k, SetKeyOfVal> _rb;
//};







typedef struct Block
{
	char ch; //每个节点保存一个字符
	struct Block *next;
}Block;
typedef struct
{
	Block *head;
	Block *tail;
	int len;
}BLString;

int StrAssign(BLString *str1, char *t);
void output(BLString *S);
Block *StrIndex(BLString *S, char *t);

int main()
{
	int flag;
	BLString *str1, *str2;
	Block *p;
	char *t;
	str1 = (BLString*)malloc(sizeof(BLString));
	str1->head = NULL;
	str1->tail = NULL;
	t = (char*)malloc(sizeof(char));
	t = "abcdefghij";
	flag = StrAssign(str1, t);
	if (flag == 1)
	{
		printf("赋值成功\n");
		output(str1);
	}
	else
		printf("赋值失败\n");

	str2 = (BLString*)malloc(sizeof(BLString));
	str2->head = NULL;
	str2->tail = NULL;
	t = (char*)malloc(sizeof(char));
	t = "def";
	flag = StrAssign(str2, t);
	if (flag == 1)
	{
		printf("赋值成功\n");
		output(str2);
	}
	else
		printf("赋值失败\n");
	p = StrIndex(str1, str2);
	printf("%c\n", p->ch);
	return 0;
}
int StrAssign(BLString *S, char *t)
{
	int i = 0;
	int len;
	Block *p, *q;
	if (S->head != NULL)
	{
		p = S->head;
		while (p != NULL)
		{
			q = p->next;
			free(p);
			p = q;
		}
		S->head = S->tail = NULL;
	}
	while (t[i] != '\0')
		i++;
	len = i;
	S->len = len;
	if (len)
	{
		p = (Block*)malloc(sizeof(Block));
		if (p == NULL)
			return(0);
		S->head = S->tail = q = p;
		i = 0;
		while (i<len)
		{
			p = (Block*)malloc(sizeof(Block));/*申请一个结点，插入到链表尾部*/
			if (p == NULL)
				return(0);
			q->next = p;
			q = p;
			p->ch = t[i];
			i++;
		}
	}
	q->next = NULL;
	S->tail = q;
	S->len = len;
	return(1);
}
void output(BLString *S)
{
	Block *p;
	int i, j;
	p = S->head->next;
	i = 0;
	while (i<S->len)
	{
		printf("%c  ", p->ch);
		p = p->next;
		i++;
	}
	printf("\n");
}
Block *StrIndex(BLString *S, BLString *T)
{
	Block *sp, *tp, *pre;
	if (T->len == 0)
		return NULL;
	sp = S->head->next;
	tp = T->head->next;
	pre = sp;
	while (sp != NULL && tp != NULL)
	{
		if (sp->ch == tp->ch)
		{
			sp = sp->next;
			tp = tp->next;
		}
		else
		{
			sp = pre->next;
			pre = sp;
			tp = T->head->next;
		}
	}
	if (tp == NULL)
		return pre;
	else
		return NULL;
}
