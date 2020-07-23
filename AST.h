class ASTNode{
	public:
		int lineno;

		AstNode( AstNode* leftNode, AstNode* rightNode);
		AstNode();

		virtual void traverse();

		AstNode* setLeftChild();
		AstNode* setRightChild();
		AstNode* setLineno();

	protected:
		ASTNode* leftChild;
		ASTNode* rightChild;
};

enum AstOp {
	val_delta,
	pos_delta,
	print,
	read
}

class ASTExpressionNode : public ASTNode {
	public:
		ASTExpressionNode( AstOp op );
		void traverse();
};

class ASTListNode : public ASTNode {
	public:
		ASTListNode( ASTExpressionNode* exp, ASTListNode* next);
		void traverse();
};

