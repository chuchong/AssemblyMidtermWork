;������������
;	b,w,dw	��ʾ������byte,word,dword
;	h		��ʾ���
;	lp		��ʾָ��
;	sz		��ʾ�ַ���
;	lpsz	��ʾ�ַ���ָ��
;	f		��ʾ������
;	st		��ʾһ�����ݽṹ
;	��������+������,��ͷСд,�����д
;�����淶!
;	������ô�д+�»���
;	ȫ�ֱ�����������������
;	������_��ͷ
;	�ֲ�������@��ͷ
;	�Զ��庯����ͷ������»���!
;	ָ��ͼĴ�����Сд
;����淶
;	�ֲ�������ַʹ��addr/lea,ȫ�ֱ�����ַʹ��offset
;	ȫ�ֱ���������.inc��
;	���ÿ⺯��������.inc��
;	ʹ��equ������=
;	ʹ��db,dw,dd������byte,word,dword
;	��תʹ��@@ �� @B(ǰ���һ��@@) ��@F(�����һ��@@)
;	�Ӻ�����ʹ��proc,uses,local��αָ��
;�����淶
;	һ������ͱ�Ŷ���ǰ������
;	һ�����ָ��Ҫ��tab����
;	��֧��ѭ��������һ��
;��������
;	����ʹ�ú�

include windows.inc
include user32.inc
includelib user32.lib
include kernel32.inc
includelib kernel32.lib
include gdi32.inc
includelib gdi32.lib
include comctl32.inc
includelib comctl32.lib
include comdlg32.inc
includelib comdlg32.lib
include msvcrt.inc
includelib msvcrt.lib

WM_CHANGE_COLOR			equ			WM_USER + 1
IDR_MENU1               equ			101
IDM_OPEN				equ			40001
IDM_SAVE				equ			40002
ID_FILE_OPENFILE		equ			40002
ID_FILE_SAVE			equ			40003
MAX_FILESIZE			equ			1000
WINDOW_WIDTH			equ			800
WINDOW_HEIGHT			equ			600
BUTTON_WIDTH			equ			40
.data
bMouseClick				db			FALSE
dwCurColor				dd			0
dwArrCustomColor		dd			16 dup(0)
;openFileN							OPENFILENAME <>
lpDwColors				dd			0h,\
									0c0c0c0h,\
									0808080h,\
									0ff0000h,\
									0800000h,\
									0ffff00h,\
									0808000h,\
									0ff00h,\
									08000h,\
									0ffffh,\
									08080h,\
									0ffh,\
									080h,\
									0ff00ffh,\
									0800080h,\
									0ffff80h,\
									0808040h,\
									0ff80h,\
									04040h,\
									080ffffh,\
									080ffh,\
									08080ffh,\
									04080h,\
									0ff0080h
COLORS_NUM				equ			($ - offset lpDwColors)

.data?
hInstance				dd			?
hWinMain				dd			? 
hWndSendTo				dd			?
hMenu					dd			?
hAccelerator			dd			?
dBuffer					dd			?
stHitPoint				POINT		<>
stMovPoint				POINT		<>
szFileNameBuffer		db			MAX_FILESIZE DUP(?)


.const
szClassName				db			'MyClass',0
szCaptionMain			db			'MyPainter',0
szColorBtnClass			db			'ColorBtn', 0
szColorBoxClass			db			'ColorBox', 0
szFilter				db			"BitMap(*.bmp)",0,"*.bmp",0
szOtherBmp				db			".bmp",0
szDefaultSaveFile		db			"1.bmp",0	