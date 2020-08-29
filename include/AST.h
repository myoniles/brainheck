#include <list> // We use lists because we do not need random access and iterators will not be invalidated by changing

#ifndef AST_H
#define AST_H

class AstNode{
	public:
		int lineno;

		AstNode();

		virtual void traverse() = 0;
		void appendChild( AstNode* node );
		void setLineno(int i);

	protected:
		std::list<AstNode*> children;
};

class AstListNode : public AstNode {
	public:
		AstListNode( );
		AstListNode(AstNode* exp);
		AstListNode(AstNode* exp, AstListNode* list);
		void traverse();
};

class AstPrintNode : public AstNode {
	public:
		void traverse();
};

class AstReadNode : public AstNode {
	public:
		void traverse();
};

class AstExpressionNode : public AstNode {
	public:
		AstExpressionNode( );
		AstExpressionNode( int val );
		virtual void traverse();

		AstExpressionNode& operator+ (AstExpressionNode const &node);

	protected:
		int val;
};

class AstValueNode : public AstExpressionNode {
	public:
		AstValueNode( );
		AstValueNode( int val );
		void traverse();
};

class AstPositionNode : public AstExpressionNode {
	public:
		AstPositionNode( );
		AstPositionNode( int val );
		void traverse();
};

class AstLoopNode: public AstNode {
	public:
		AstLoopNode( AstListNode* inside );
		void traverse();
	private:
		AstListNode* inside;
};

#endif
