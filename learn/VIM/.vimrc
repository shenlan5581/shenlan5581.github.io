set nu
syntax on
colorscheme pablo
“颜色主题
set ts=2
"tab 长度
:set shiftwidth=2
"缩进长度


imap ` <Esc>    
nmap ~ :sh  <CR>
nmap ` <Esc>
nmap <F12> :vsp ./ <CR>
nmap    <F9>     :vertical resize -3<CR> 
nmap    <F10>   :vertical resize +3<CR>
imap     <F8>      <Esc>:w<CR>

"高亮查找匹配
"set hlsearch
"手动折叠
"set fdm=manual
"去除扩展
"set nocompatible
