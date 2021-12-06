var portfolioJson;
// Write Jacascript Here
function LoadPortfolioWebsite(){
 LoadPortfolio("Test.json");
}

function LoadPortfolio(SettingFileLocation) {
  fetch(SettingFileLocation).then(function(resp) {return resp.json();}).then(function(data){console.log(data); portfolioJson = data; CreateHTMLProjectElements();});
}

function CreateHTMLProjectElements(){
    for (let i = 0; i < 4; i++)
    {
        // Project number: 0
        //Element 0
        // Text Component
        var portolioElemet0 = document.getElementById("1");
        portolioElemet0.innerHTML = "Default Text";

        // Project number: 1
        //Element 0
        // Text Component
        var portolioElemet0 = document.getElementById("2");
        portolioElemet0.src = "https://www.youtube.com/embed/KASOa5JMMJ0";

        // Project number: 2
        //Element 0
        // Text Component
        var portolioElemet0 = document.getElementById("3");
        portolioElemet0.href = "www.google.com";

        // Project number: 3
        //Element 0
        // Text Component
        var portolioElemet0 = document.getElementById("4");
        portolioElemet0.src = "Put Image Directory Here";

    }
}

