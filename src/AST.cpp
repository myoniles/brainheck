#include "../include/AST.h"
#include <cstddef>
#include <stdio.h>
#include <list> // We use lists because we do not need random access and iterators will not be invalidated by changing

#ifndef AST
#define AST

void yyerror(const char* s);
//char* ptr, mem;

char mem[30000] = {0};
char* ptr = mem;

void status_update(){
	printf("current ptr:\t%p,\tcurrent *ptr:\t%d\n", ptr, *ptr);
}

AstNode::AstNode()
{
}

void AstNode::setLineno( int i )
{
	this->lineno = i;
}

AstListNode::AstListNode()
:AstNode()
{
}

AstListNode::AstListNode(AstNode* exp)
:AstNode()
{
	children.push_back(exp);
}

AstListNode::AstListNode(AstNode* exp, AstListNode* next) :
AstNode(){
	children = next->children;
	children.push_back(exp);
}

void AstListNode::traverse(){
	for (AstNode* child : children)
		child->traverse();
}

AstExpressionNode::AstExpressionNode()
:AstNode()
{
}

AstExpressionNode::AstExpressionNode(int val) :
AstNode(){
	this->val = val;
}

AstExpressionNode operator+ (AstExpressionNode const &node){}
void AstExpressionNode::traverse(){};

AstValueNode::AstValueNode():AstExpressionNode(0){}
AstValueNode::AstValueNode( int val ):AstExpressionNode(val){}

void AstValueNode::traverse(){
	*ptr += val;
}

AstPositionNode::AstPositionNode():AstExpressionNode(0){}
AstPositionNode::AstPositionNode( int val ):AstExpressionNode(val){}

void AstPositionNode::traverse(){
	ptr += val;
}

void AstPrintNode::traverse(){
	printf("%c", *ptr);
}

void AstReadNode::traverse(){
	*ptr = getchar();
}

void printbyte(char a){
	int i;
	for (i = 0; i < 8; i++) {
			printf("%d", !!((a << i) & 0x80));
	}
	printf(" ");
}

AstLoopNode::AstLoopNode(AstListNode* inside):AstNode(){this->inside = inside;}

void AstLoopNode::traverse(){
	if (inside==NULL)
		return;
	char* og_ptr = ptr;
	while(*ptr){
		inside->traverse();
	}
}
#endif
