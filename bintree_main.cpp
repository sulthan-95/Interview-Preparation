#include"btreeinsertion and preorder.cpp"
int main()
{
    root=insert(root,5);
    root=insert(root,10);
    root=insert(root,15);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,30);
    root=insert(root,35);
    root=insert(root,40);
    cout<<"\npre order traversal:\n";
    preorder(root);
    cout<<"\nin order traversal:\n";
    inorder(root);
    cout<<"\npost order traversal:\n";
    postorder(root);
    cout<<"\npre order traversal non recursive:\n";
    preordernonrec(root);
    cout<<"\nin order traversal non recursive:\n";
    inordernonrec(root);
    cout<<"\nlevel order traversal:\n";
    levelorder(root);
    cout<<"\nmaximum element is:"<<findmax(root);
    cout<<"\nminimum element is:"<<findmin(root);
    cout<<"\nmaximum element using non rec is:"<<findmaxnonrec(root);
    cout<<"\nminimum element using non rec is:"<<findminnonrec(root);
    if(find(root,25))
    cout<<"\n"<<25<<" is in the tree";
    else
    cout<<"\n"<<25<<" is not in the tree";
    if(findnonrec(root,50))
    cout<<"\n"<<50<<" is in the tree";
    else
    cout<<"\n"<<50<<" is not in the tree";
    cout<<"\nsize of the tree:"<<sizetree(root);
    cout<<"\nsize of the tree using non recursive:"<<sizetreenonrec(root);
    cout<<"\n###################level order reverse print##################";
    levelorderrev(root);
    cout<<"\nheight of the tree:"<<heighttree(root);
    cout<<"\nheight of the tree non recursive:"<<heighttreenonrec(root);
    cout<<"\n###############DEEPEST NODE ########################";
    cout<<"\nDEEPEST NODE:"<<deepestnode(root);
    /*deletenode(root,20);*?
    cout<<"\nafter deleting the  node with the value:"<<20;
    levelorder(root);
    /*cout<<"\n###################deleting the tree######################";
    deletetree(root);*/
    cout<<"\nno of leaves in the tree:"<<noofleaves(root);
    cout<<"\nno of full nodes in the tree:"<<nooffullnodes(root);
    cout<<"\nno of half nodes in the tree:"<<noofhalfnodes(root);
    root1=insert(root1,5);
    root1=insert(root1,10);
    root1=insert(root1,15);
    root1=insert(root1,20);
    root1=insert(root1,25);
    root1=insert(root1,30);
    root1=insert(root1,35);
    cout<<"\nlevel order tracersal of second tree:";
    levelorder(root1);
    cout<<"\n################checking identity of two trees####################";
    if(identical(root,root1))
    cout<<"\nboth are identical";
    else
    cout<<"\nboth are not identical";
    cout<<"\ndia meter of the tree:"<<diameter(root);
    cout<<"\nfind which level has maximum sum:"<<maxsumlevel(root);
    cout<<"\nprint the all of its root-to-leaf paths:";
    int p[10],l=0;
    printpath(root,p,l);
    cout<<"\ncheck is there any path exist that has the given sum:";
    cout<<"\nenter sum:";
    int summ;
    cin>>summ;
    if(checksumpath(root,summ))
    cout<<"\nyes exist";
    else
    cout<<"\n no doesnt exist";
    cout<<"\nsum of all the nodes in the tree:"<<sumtree(root);
    struct btree *root3=mirror(root);
    cout<<"\nmirror tree root3:\n";
    levelorder(root3);
    root3=mirror(root3);
    cout<<"\nmirror tree root3:\n";
    levelorder(root3);
    cout<<"\nfind ancestor of the node:";
    cout<<"\nenter tne node:";
    int anc;
    cin>>anc;
    cout<<"\nancestors of node with value:"<<anc;
    ancestors(root,anc);
    return 0;
}
