var portfolioJson;
// Write Jacascript Here
function LoadPortfolioWebsite(){
 LoadPortfolio("/Users/davidtaylormacbookpro/Documents/GitHub/Backend-for-Website-Text/Test1.json");
}

function LoadPortfolio(SettingFileLocation) {
  //fetch(SettingFileLocation).then(function(resp) {return resp.json();}).then(function(data){console.log(data); portfolioJson = data; CreateHTMLProjectElements();});
  CreateHTMLProjectElements();
}

function CreateHTMLProjectElements(){


 // Project number: 0
 //Element 0
 // Text Component
 var portolioElemet = document.getElementById("TEMP1 ");
 portolioElemet.innerHTML = "Default Text";

 // Project number: 1
 //Element 0
 // Youtube Component
 var portolioElemet = document.getElementById("Temp2 ");
 portolioElemet.src = "Default Text";

 // Project number: 2
 //Element 0
 // Link Component
 var portolioElemet = document.getElementById("Temp3 ");
 portolioElemet.href = "www.google.com";

 // Project number: 3

}

