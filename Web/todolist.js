const addBtn = document.querySelector('.add-btn')
const list = document.querySelector('.todo-list')
const input = document.querySelector('.todo-input')
const delBtn = document.querySelector('.del-btn')
const search = document.querySelector('.search-input').textContent;
var cdt = new Date();
var cdtr = cdt.getFullYear()+'-'+(cdt.getMonth()+1)+'-'+(cdt.getDate())+'-'+(cdt.getHours())+':'+(cdt.getMinutes());
function loadTodos(){
    const save = localStorage.getItem('지훈')

    if(save){
        list.innerHTML
    }
}

loadTodos()

function saveTodos(){
    localStorage.setItem('지훈', list.innerHTML)
}


addBtn.addEventListener('click',function(){
  
    const txt = input.value

    if(txt.trim() === ''){
        alert('내용 입력하세요')
        return
    }
    const html = `<li class='todo-item'>
    <p class="todo-text"> ${txt}</p>
    <p>${cdtr}</p>
    <button class="del-btn">삭제</button>
    </li>
    `

    list.innerHTML += html
    saveTodos()

    input.value =''
})

list.addEventListener('click',function(e){
    if (e.target.classList.contains('del-btn')){
        e.target.parentElement.remove()
        saveTools()}
    if (e.target.tagName === 'P'){
        e.target.classList.toggle('completed');
        saveTools()}
    if(e.target.classList.contains('clear-btn')){
        e.target.list.remove()
    }
    saveTools()
})
function filterUsers(value) {
  users.forEach((user) => {
    const isVisible =
      search.toLowerCase().includes(value) ||
      search.toLowerCase().includes(value);
    user.element.classList.toggle("hide", !isVisible);
  });
}
