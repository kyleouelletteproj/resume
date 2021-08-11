const socket = io('http://localhost:3000')
const postContainer = document.getElementById('post-container')
const postForm = document.getElementById('send-container')
const postInput = document.getElementById('post-input')


const name = prompt('What is your name?')
appendPost('You joined')
socket.emit('new-user', name)

socket.on('post-message', data => {
  appendPost(`${data.name}: ${data.post}`)
})

socket.on('user-connected', name => {
  appendPost(`${name} connected`)
})

socket.on('user-disconnected', name => {
  appendPost(`${name} disconnected`)
})

postForm.addEventListener('submit', e => {
  e.preventDefault()
  const post = postInput.value
  appendPost(`You: ${post}`)
  socket.emit('send-post-message', post)
  postInput.value = ''
})

function appendPost(post) {
  const postElement = document.createElement('div')
  postElement.innerText = post
  postContainer.append(postElement)
}
