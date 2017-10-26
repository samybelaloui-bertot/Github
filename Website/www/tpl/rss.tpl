<!DOCTYPE html>

<html lang="fr">
<head>
  <title> Acupuncteurs en médecine traditionnelle chinoise </title>
  <meta name="description" content="Acupuncteurs en médecine traditionnelle chinoise" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" media="screen" type="text/css" href="../css/style.css" />
  <script src="../js/jquery-3.2.0.min.js" type="text/javascript"></script>
  {include file='./header.tpl'}

<body>

         <nav>
          <ul>
            <li> <a  accesskey="1" href="index.php?page=accueil">Page d'accueil (1) </a> </li>
            <li> <a accesskey="2" href="index.php?page=categorie">Accès aux données (2)</a> </li>
            <li> <a accesskey="3" href="index.php?page=info">Page d'information (3) </a> </li>
            <li> <a class="active" accesskey="4" href="index.php?page=rss">RSS (4)</a> </li>
            <li accesskey="5" id="connex"> {connexion} </li>
          </ul>
         </nav>
         <div class="gros_titre">
           <h1>ACUPUNCTURE</h1>

           <h2>RSS</h2>
           <img src="../images/rss.png" alt="image de flux RSS" height="42" width="42">

         </div>

      <div id="Div_XML"></div>
      <script type="text/javascript">
      $(document).ready(function()
      {
        $.ajax({
                type: "GET",
                url: "rss.xml",
                dataType: "xml",
                success:function(xml)
                      {
                          console.log('ok');
                          $(xml).find("item").each(
                            function ()
                            {
                              var title = $(this).attr('title');
                              var link = $(this).find('link').text();
                              var description = $(this).find('description').text();
                              $('<div class="items"' + title + '></div>').html('<a href="' + link + '">' + description + '</a>').appendTo('#Div_XML');
                            });
                      }


              });
      }
      );


  </script>


</body>

{include file='./footer.tpl'}
