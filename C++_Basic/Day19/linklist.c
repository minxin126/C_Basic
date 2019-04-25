#include<stdio.h>
#include "stdlib.h"
#include "string.h"

#include "linklist.h"

typedef struct _tag_LinkList
{
	//这个句柄里面，需要保存所有节点信息。需要有一个起始点
	//就是带头节点的链表。。。
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create()
{
	TLinkList *ret = (TLinkList *)malloc(sizeof(TLinkList));
	if (ret == NULL)
	{
		return NULL;
	}
	//memset(ret, 0, sizeof(TLinkList));
	ret->header.next = NULL;
	ret->length = 0;
	return ret;
}

void LinkList_Destroy(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
	return;
}

void LinkList_Clear(LinkList* list)
{
	TLinkList *tList = NULL;

	if (list == NULL)
	{
		return;
	}
	tList = (TLinkList *)list;
	tList->length = 0;
	tList->header.next = NULL;
	return;
}

int LinkList_Length(LinkList* list)
{
	TLinkList *tList = (TLinkList *)list;
	if (tList == NULL)
	{
		return 0;
	}

	return tList->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	return NULL;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	return NULL;
}