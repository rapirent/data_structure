�}�o���x(Development Platform):win8.1
�ϥζ}�o����(Development environment):	minGW & sublime
�{���\��(Program Functions):
	���{���i�H�ھڨϥΪ̪���J�سy�@�ʤG���j�M��A�öi�Ө̷ӨϥΪ̿�ܪ��Ҧ��ӧR���𤤪��`�I�ΦL�X��e����
�{���]�p(Program design):
	
<#define MAX_TREE 1000>
	�ŧi�F�@�ʾ�̦h���`�I�ƶq
<struct tree�Ktypedef struct tree* tree_pointer;>
	���ӽҥ�����k�ŧi�F��`�I�M����Ъ����A���e
<void insert(tree_pointer *node,int k);>
	�ھڶǤJ���ڸ`�I�A�s�y����k���`�I�ç⥦�s���b�ڸ`�I�ҥN���𤤥��T��m�W�C
	�����Hinsert_search�禡��Xk�b�ڸ`�I�N��𪺤����`�I�A�Y�O���`�I���s�b�h�N�s�y���`�I���b�Ӧ�m
	�Y�s�b�A�h�������`�I�Mk���ȡA��k���b���T����m�C
<tree_pointer insert_search(tree_pointer node,int k);>
	�N���X�ǤJ�ڸ`�I����A�M��O�_�s�bk�A�Ǧ����k�����m����m�A�æ^�Ǩ���`�I
<void delTree(tree_pointer *root,int k);>
	�R���ǤJ�ڸ`�I�N���𤤡A������k���`�I�C
�����Hdel_search��X����k�`�I�M����`�I�A�ë��Ӧ��R�����p�����G
1.	k�`�I�����`�I
2.	k�`�I�S�����l�`�I
3.	k�`�I�S���k�l�`�I
4.	k�`�I�����k�l�`�I
�����p�Ӱ��B�z�A

�p�Gk�`�I�����`�I�A�h�����R���C�Y�O�L�S�����l�`�I�Υk�l�`�I�A�h
�P�_�O�_k�`�I���ڸ`�I�A�Y�O�ڸ`�I�A�h�������k���l�`�I���N���A�ýվ�𪺵��c�C�Y���O�A�h�R����u����µ��c���վ�
	�p�Gk�`�I�����k�l�`�I�A�h���ӧU�Щһ����v���W�h���R��
<tree_pointer del_search(tree_pointer nood,int k,tree_pointer*);>
	���X�ǤJ���ڸ`�I�N���A�ç�X�䤤������k���`�I�A�æ^�ǥ��C�������~�A��H���бo�����`�I�C
<void level_order(tree_pointer *);>
	�H���h���X�æL�X�@�~�n�D���L�X���G�C
	�����Hlevel_order_search�o���ʾ𪺶��h�ơA�íp��X�����ӦL�X���`�I�ơC
	�A�H�@�զ�C�A�H���h�覡���X��ʾ�C���F�L�XX�A�b�J��𵲺c���Ÿ`�I�ɡA�h�s�y�s���`�I�b����m�W�A�䤸���Ȭ�-1�A�p���b��C���X�Ӥ����ɡA�K�i�P�_��key�ȨӨM�w�O�_�L�XX
<int level_order_search(tree_pointer node);>
	�H���j�覡���X�@�ʾ�A����X�츭�`�I�ɡA�^��1�A�èC�@�Ӷ��h�N���ȥ[�@�A�̫�o��ڸ`�I���k�l�𪺶��h�ơA�ä���̸��j�A�Ǧ^�̤j�̡]�𤧳̰����h�^

< int main(void)>
	�D�禡���A���ŧi�@�Ӧr���}�C�A�H�@�Ӱj�餣�_����scanf�ӱ����C�檺��J�]�Ǧ��P�_�H������j�}�^�A�ä���Hstrtok�禡�o��H�ť���j�}���Ʀr�C
	�Y�O�ϥΪ̿�JE�A�h���W�I�slevel_order�禡�A�q�ӦL�X��ʾ�
	�Y�ϥΪ̿�JD�A�hbreak�X���j��A�i�ӦA�H�ۦP�覡���o�R���`�I
	�R���`�I�j�餤�A�Y�ϥΪ̿�JE�A�h�I�slevel_order�禡�A�q�ӦL�X��ʾ�
