const openModalButtons = document.querySelectorAll('[data-modal-target]')
const closeModalButtons = document.querySelectorAll('[data-close-button]')
const overlay = document.getElementById('overlay')

var mode = true;
input_type = "numerical";

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

  show('choose-option', 'numerical');
}

function closeModal(modal) {
  if (modal == null) return
  modal.classList.remove('active')
  overlay.classList.remove('active')

  setTimeout(() => {show('choose-option');}, 250);
}

function show(value, type){

  console.log(input_type)
  if(typeof input_type == "undefined" || typeof input_type == "null") {
    input_type = "numerical"; 
  }

  document.getElementById(input_type).classList.remove("active");
  input_type = type;
  document.getElementById(input_type).classList.add("active");
  
  var divsToHide = document.getElementsByClassName("option-tab");
  for(var i = 0; i < divsToHide.length; i++){
    divsToHide[i].style.visibility = "hidden";
  }
  document.getElementById(value).style.visibility = "visible" ;
}

function getData() {
  
  var divsToHide = document.getElementsByClassName("option-tab");
    var optionTab = divsToHide[0];

    // getting visible option tab
    for(var i = 0; i < divsToHide.length; i++){
      if(divsToHide[i].style.visibility == "visible") {
        optionTab = divsToHide[i];
        i = divsToHide.length;
      }
    }

    var options = new Map();

    // adding properties to map
    var input_fields = optionTab.getElementsByClassName("option-text-input");
    for(var i = 0; i < input_fields.length; i++) {
      if(input_fields[i].value == "") {
        if(input_fields[i].placeholder == "space")
          options[input_fields[i].id] = " ";
        else
          options[input_fields[i].id] = input_fields[i].placeholder;
      } else {
        options[input_fields[i].id] = input_fields[i].value;
      }
    }
    
    console.log(options);
  
  if(document.getElementById("input-output").textContent == "input") {
    document.getElementById("hidden-input-type").textContent = input_type;
    document.getElementById("hidden-input-div").textContent = JSON.stringify(options);
  } else{
    document.getElementById("hidden-output-type").textContent = input_type;
    document.getElementById("hidden-output-div").textContent = JSON.stringify(options);
  }
  alert("Opzioni caricate");
}

function convert()
{  
  var input_txt = '{"data":';
  console.log(document.getElementById("custom-textarea").value);
  input_txt += '"' + document.getElementById("custom-textarea").value  + '"' + ', ';

  if(document.getElementById("hidden-input-div").textContent == "")
    input_txt += '"inputOpt":"", ';
  else
    input_txt += '"inputOpt":'+ document.getElementById("hidden-input-div").textContent + ', ';
  
  if(document.getElementById("hidden-output-div").textContent == "")
    input_txt += '"inputOpt":""}';
  else
    input_txt += '"outputOpt":' + document.getElementById("hidden-output-div").textContent + '}';

  console.log(JSON.parse(input_txt));
}

function swap()
{
  var temp = document.getElementsByClassName("output-textarea-box")[0].textContent;
  document.getElementsByClassName("output-textarea-box")[0].textContent = '';
  
  //console.log(temp);
  if(temp == "")
    document.getElementById("custom-textarea").value = '';
  else
    document.getElementById("custom-textarea").value = temp;


  var temp = document.getElementById("hidden-input-div").textContent;
  document.getElementById("hidden-input-div").textContent = document.getElementById("hidden-output-div").textContent;
  document.getElementById("hidden-output-div").textContent = temp;

  temp = document.getElementById("hidden-input-type").textContent;
  document.getElementById("hidden-input-type").textContent = document.getElementById("hidden-output-type").textContent;
  document.getElementById("hidden-output-type").textContent = temp;
}

/* Esempio JSON
{
  data: "847584",
  inputOpt: {
    type: "numeric",
    base: "10",
    decimalSeparator: ",",
    precision: "4"
  },
  outputOpt: {
    type: "biquinary",
    numberSeparator: " ",
    decimalSeparator: "-"
  }
}
*/