
"<k0> - <k9> 小键盘 0 到 9
"<S-...> Shift＋键
"C-...> Control＋键
"<M-...> Alt＋键 或 meta＋键
"<A-...> 同 <M-...>
"<Esc> Escape 键
"<Up> 光标上移键
"<Space> 插入空格


set nu
syntax on
colorscheme pablo
"颜色主题
set ts=2
"tab 长度
:set shiftwidth=2
"缩进长度

vmap ` <C-[> 
imap `  <C-[>    
nmap ~ :sh  <CR>
nmap ` <C-[> 
nmap <F12> :vsp ./ <CR>
nmap    <F9>     :vertical resize -3<CR> 
nmap    <F10>   :vertical resize +3<CR>
"imap     <F8>      <Esc>:w<CR>

"高亮查找匹配
"set hlsearch
"手动折叠
"set fdm=manual
"去除扩展
"set nocompatible
