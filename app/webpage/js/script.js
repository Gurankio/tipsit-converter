const openModalButtons = document.querySelectorAll('[data-modal-target]')
const closeModalButtons = document.querySelectorAll('[data-close-button]')
const overlay = document.getElementById('overlay')

var mode = true;
input_type = "numeric";

openModalButtons.forEach(button => {

  button.addEventListener('click', () => {
    document.getElementById("modal").style.transition = "200ms ease-in-out";
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

  show('choose-option', 'numeric');
}

function closeModal(modal) {
  reset()
  if (modal == null) return
  modal.classList.remove('active')
  overlay.classList.remove('active')

  setTimeout(() => {show('choose-option');}, 250);
}

function show(value, type){

  if(typeof input_type == "undefined" || typeof input_type == "null") {
    input_type = "numeric"; 
  }
  if(typeof type == "undefined" || typeof type == "null") {
    type = "numeric"; 
  }

  console.log(input_type+"->"+type);
  document.getElementById(input_type).classList.remove("active");
  input_type = type;
  document.getElementById(input_type).classList.add("active");
  
  var divsToHide = document.getElementsByClassName("option-tab");
  for(var i = 0; i < divsToHide.length; i++){
    divsToHide[i].style.visibility = "hidden";
  }
  document.getElementById(value).style.visibility = "visible" ;
}

function reset()
{
  var divsToHide = document.getElementsByClassName("option-tab");

  // getting visible option tab
  for(var i = 0; i < divsToHide.length; i++){
    var input_fields = divsToHide[i].getElementsByClassName("option-text-input");
    for(var j = 0; j < input_fields.length; j++)
      input_fields[j].value='';
  }
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
  
  if(!inputCheck()) {
    alert("Malformed input!");
    return -1;
  }

  console.log(document.getElementById("custom-textarea").value);

  /** GETTING DATA */
  input_txt += '"' + document.getElementById("custom-textarea").value  + '"' + ', ';
  input_txt += '"inputType": "' + document.getElementById("hidden-input-type").textContent + '", ';

  if(document.getElementById("hidden-input-div").textContent == "")
    input_txt += '"inputOptions":"", ';
  else
    input_txt += '"inputOptions":'+ document.getElementById("hidden-input-div").textContent + ', ';
  
  input_txt += '"outputType": "' + document.getElementById("hidden-output-type").textContent + '", ';

  if(document.getElementById("hidden-output-div").textContent == "")
    input_txt += '"outputOptions":""}';
  else
    input_txt += '"outputOptions":' + document.getElementById("hidden-output-div").textContent + '}';

  //   CONVERTER MODULE
  const converter = require("converter");

  var map = JSON.parse(input_txt);
  if(map["inputType"] == "fiscal" || map["outputType"] == "fiscal")
    if(!(map["inputType"] == "fiscal" && map["outputType"] == "fiscal")){
      alert("Wait! That's illegal");
      return -1;
    }

  console.log(JSON.parse(input_txt));
  
  if(document.getElementById("p5-canvas").innerHTML != "")
    document.getElementById("p5-canvas").innerHTML = "";

  if(document.getElementById("hidden-output-type").textContent == "segment7") {
    createDigits(0.4, converter.convert(JSON.parse(input_txt)).split("_"));
  } else {
    document.getElementById("p5-canvas").innerHTML = "";
  }

  try {
    var output = converter.convert(JSON.parse(input_txt));
  } catch (err) {
    var output = "0";   
  }
  
  if(output != null)
    document.getElementById("output-value").textContent = output;
  
}

function swap()
{
  // swapping options
  temp = document.getElementById("hidden-input-div").textContent;
  document.getElementById("hidden-input-div").textContent = document.getElementById("hidden-output-div").textContent;
  if(temp != null)
    document.getElementById("hidden-output-div").textContent = temp;

  temp = document.getElementById("hidden-input-type").textContent;
  document.getElementById("hidden-input-type").textContent = document.getElementById("hidden-output-type").textContent;
  if(temp != null)
    document.getElementById("hidden-output-type").textContent = temp;

  // swapping values
  temp = document.getElementById("output-value").textContent;
  document.getElementById("output-value").textContent = '';
  if(temp != null)
    document.getElementById("custom-textarea").value = temp;
  
  if(document.getElementById("p5-canvas").innerHTML != "")
    document.getElementById("p5-canvas").innerHTML = "";
}

function inputCheck() {
  let data = document.getElementById("custom-textarea").value;
  let type = document.getElementById("hidden-input-type").textContent;
  let opt = JSON.parse(document.getElementById("hidden-input-div").textContent);
  console.log(opt);
  let regex = ".";
  let alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@_";

  switch(type) {
    case "roman":
      //    /^[ivxlcdmIVXLCDM]$/g
      regex = '^[ivxlcdmIVXLCDM]+$';
      break;
    case "numeric":
      //    /^[0-9]+(\.[0-9]{0,8})?$/g
      regex = '^-?[ '+alphabet.substr(0, opt['base'])+']+(\\'+opt["decimalSeparator"][0]+'[ '+alphabet.substr(0, opt['base'])+']{0,'+opt["precision"]+'})?$';;
      break;
    case "bcd": case "aiken": case "quinary": case "xs3": case "xs3r": case "grey":
      //    /^([01]{4}( [01]{4})*)+(\.([01]{4}( [01]{4})*))$/g
      regex = '^-?([01]{4}(' + opt["numberSeparator"][0] + '[01]{4})* ?)+(\\' + opt["decimalSeparator"][0] + '([01]{4}(' + opt["numberSeparator"][0] + '[01]{4})* ?)+)?$';
      break;
    case "biquinary":
      //    /(?=^[01]{2} [01]{5}( [01]{2} [01]{5})*(\.[01]{2} [01]{5}( [01]{2} [01]{5})*)?$)^0*10* 0*10*( 0*10* 0*10*)*(\.0*10* 0*10*( 0*10* 0*10*)*)?$/g
      var digit_format = '0?1{1}0*10*';
      regex = '(?=^-?[01]{7}('+opt["numberSeparator"][0]+'[01]{7})*(\.[01]{7}('+opt["numberSeparator"][0]+'[01]{7})*)?$)^-?'+digit_format+'('+opt["numberSeparator"][0]+digit_format+')*(\.'+digit_format+'('+opt["numberSeparator"][0]+digit_format+')*)?$';
      break;
    case "twoOnFive":
      //    /(?=^[01]{5}( [01]{5})*(\.[01]{5}( [01]{5})*)?$)^0*10*10*( 0*10*10*)*(\.0*10*10*( 0*10*10*)*)?$/g
      var digit_format = '0*10*10*';
      regex = '^-?(?=^[01]{5}('+opt["numberSeparator"][0]+'[01]{5})*(\.[01]{5}('+opt["numberSeparator"][0]+'[01]{5})*)?$)^0*10*10*('+opt["numberSeparator"][0]+'0*10*10*)*(\.0*10*10*('+opt["numberSeparator"][0]+'0*10*10*)*)?$';
      break;
    case "oneOfN":
      //    /(?=^[01]{n}( [01]{n})*(\.[01]{n}( [01]{n})*)?$)^0*10*( 0*10*)*(\.0*10*( 0*10*)*)?$/g
      regex = '(?=^[01]{'+opt["n"]+'}('+opt["numberSeparator"][0]+'[01]{'+opt["n"]+'})*(\.[01]{'+opt["n"]+'}('+opt["numberSeparator"][0]+'[01]{'+opt["n"]+'})*)?$)^0*10*('+opt["numberSeparator"][0]+'0*10*)*(\.0*10*('+opt["numberSeparator"][0]+'0*10*)*)?$';
      break;
    case "segment7":
      //    /[01]{7}( [01]{7})*/g
      regex = '^[01]{7}(_[01]{7})*$';
      break;
    case "fiscal":
      regex = '^[\\w ]+;[\\w ]+;[MF];[\\w ]+;\\w{2};\\d{2}.\\d{2}.\\d{4}$';
      break;
    default:
      regex = '.';
  }
  
  if(type=="numeric" && opt["base"] <= 36)
    r = new RegExp(regex, "i");
  else
    r = new RegExp(regex);

  console.log(r);
  if(!r.test(data)) {
    console.log("INPUT ERROR");
    document.getElementById("custom-textarea").style.border = "2px solid red"; 
    return false;
  } else {
    console.log("INPUT OK");
    document.getElementById("custom-textarea").style.border = "2px solid grey";
    return true;
  }  
}

inputDiv = document.getElementById("hidden-input-type");
inputDiv.addEventListener('DOMSubtreeModified', function(){
  document.getElementById("input-type").textContent = document.querySelectorAll("button#"+inputDiv.textContent)[0].textContent;
});

outputDiv = document.getElementById("hidden-output-type");
outputDiv.addEventListener('DOMSubtreeModified', function(){
  document.getElementById("output-type").textContent = document.querySelectorAll("button#"+outputDiv.textContent)[0].textContent;
});

/* Esempio JSON

{
  data: "847584", 
  inputType: "numeric", 

  inputOptions: {
    base: "10",
    decimalSeparator: ",",
    precision: "4"
  }, 

  outputType: "biquinary", 

  outputOptions: {
    numberSeparator: " ",
    decimalSeparator: "-"
  }
}
*/