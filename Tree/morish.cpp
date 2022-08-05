public void morrisTraversal(TreeNode root){
		TreeNode temp = null;
		while(root!=null){
			if(root.left!=null){
				// connect threading for root
				temp = root.left;
				while(temp.right!=null && temp.right != root)
					temp = temp.right;
				// the threading already exists
				if(temp.right!=null){
					temp.right = null;
					System.out.println(root.val);
					root = root.right;
				}else{
					// construct the threading
					temp.right = root;
					root = root.left;
				}
			}else{
				System.out.println(root.val);
				root = root.right;
			}
		}
	}