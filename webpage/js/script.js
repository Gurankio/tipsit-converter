const openModalButtons = document.querySelectorAll('[data-modal-target]')
const closeModalButtons = document.querySelectorAll('[data-close-button]')
const overlay = document.getElementById('overlay')

var input_options = new Map();
input_options["type"] = "numerical";
var output_options = new Map();

openModalButtons.forEach(button => {
  button.addEventListener('click', () => {
    const modal = document.querySelector(button.dataset.modalTarget)
    openModal(modal)
  })
})

overlay.addEventListener('click', () => {
  const modals = document.querySelectorAll('.modal.active')
  modals.forEach(modal => {
    closeModal(modal)
  })
})

closeModalButtons.forEach(button => {
  button.addEventListener('click', () => {
    const modal = button.closest('.modal')
    closeModal(modal)
  })
})

function openModal(modal) {
  if (modal == null) return
  modal.classList.add('active')
  overlay.classList.add('active')

  show('choose-option');
}

function closeModal(modal) {
  if (modal == null) return
  modal.classList.remove('active')
  overlay.classList.remove('active')

  setTimeout(() => {show('choose-option');}, 250);
}

function show(value, type){

  console.log(input_options)
  if(typeof input_options["type"] === 'undefined') {
    input_options["type"] = "numerical"; 
  }

  document.getElementById(input_options["type"]).classList.remove("active");
  //console.log(input_options["type"] + " -> " + type);
  input_options["type"] = type;
  document.getElementById(input_options["type"]).classList.add("active");
  
  var divsToHide = document.getElementsByClassName("option-tab");
  for(var i = 0; i < divsToHide.length; i++){
    divsToHide[i].style.visibility = "hidden";
  }

  document.getElementById(value).style.visibility = "visible" ;
}

function getData() {
  var divs = document.getElementsByClassName("hidden-button");
  for(var div in divs){
    if(div.style.visibility == "visible") {
      var type = div.getElementsByClassName
      console.log(type);
    }
  }
}