#ifndef _MY_LINKSTACK_H_
#define _MY_LINKSTACK_H_

typedef void LinkStack;

extern LinkStack* LinkStack_Create();

extern void LinkStack_Destroy(LinkStack* stack);

void LinkStack_Clear(LinkStack* stack);

int LinkStack_Push(LinkStack* stack, void* item);

void* LinkStack_Pop(LinkStack* stack);

void* LinkStack_Top(LinkStack* stack);

int LinkStack_Size(LinkStack* stack);

#endif //_MY_LINKSTACK_H_fn
