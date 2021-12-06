var portfolioJson;
// Write Jacascript Here
function LoadPortfolioWebsite(){
 LoadPortfolio("/Users/davidtaylormacbookpro/Documents/GitHub/Backend-for-Website-Text/Test1.json")
}

function LoadPortfolio(SettingFileLocation) {
  //fetch(SettingFileLocation).then(function(resp) {return resp.json();}).then(function(data){console.log(data); portfolioJson = data; CreateHTMLProjectElements();});
  CreateHTMLProjectElements();
}

function CreateHTMLProjectElements(){
 // Project number: 0
 //Element 0
 // Text Component
 var portolioElemet0 = document.getElementById("TEMP1 ");
 portolioElemet0.innerHTML = "Default Text";

 // Project number: 1
 //Element 0
 // Youtube Component
 var portolioElemet1 = document.getElementById("Temp2 ");
 portolioElemet0.src = "Default Text";

 // Project number: 2
 //Element 0
 // Link Component
 var portolioElemet2 = document.getElementById("Temp3 ");
 portolioElemet0.href = "www.google.com";

 // Project number: 3

}