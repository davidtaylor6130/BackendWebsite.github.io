var portfolioJson;
// Write Jacascript Here
function LoadPortfolioWebsite(){
 LoadPortfolio("Test.json")
}

function LoadPortfolio(SettingFileLocation) {
  //fetch(SettingFileLocation).then(function(resp) {return resp.json();}).then(function(data){console.log(data); portfolioJson = data; CreateHTMLProjectElements();});
  CreateHTMLProjectElements();
}

function CreateHTMLProjectElements(){


 // Project number: 0
 //Element 0
 // Text Component
 var portolioElemet0 = document.getElementById("NO ID SET");
 portfolioElement.innerHTML = "Default Text";

 // Project number: 1
 //Element 0
 // Youtube Component
 var portolioElemet0 = document.getElementById("NO ID SET");
 portfolioElement.src = "Default Text";

 // Project number: 2
 //Element 0
 // Link Component
 var portolioElemet0 = document.getElementById("NO ID SET");
 portfolioElement.href = "www.google.com";

 // Project number: 3
 //Element 0
 // Image Component
 var portolioElemet0 = document.getElementById("NO ID SET");
 portfolioElement.src = "Put Image Directory Here";

}

