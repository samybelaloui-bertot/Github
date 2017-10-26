<?php
/* Smarty version 3.1.31, created on 2017-04-02 14:43:16
  from "C:\wamp\www\info.tpl" */

/* @var Smarty_Internal_Template $_smarty_tpl */
if ($_smarty_tpl->_decodeProperties($_smarty_tpl, array (
  'version' => '3.1.31',
  'unifunc' => 'content_58e10e04881069_78839548',
  'has_nocache_code' => false,
  'file_dependency' => 
  array (
    'eeed5bb581c319294530980c05e7efad4c7cff57' => 
    array (
      0 => 'C:\\wamp\\www\\info.tpl',
      1 => 1491144191,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
    'file:./header.tpl' => 1,
    'file:./footer.tpl' => 1,
  ),
),false)) {
function content_58e10e04881069_78839548 (Smarty_Internal_Template $_smarty_tpl) {
if (!is_callable('smarty_function_connexion')) require_once 'C:\\wamp\\www\\smarty\\plugins\\function.connexion.php';
?>
<!DOCTYPE html>

<html lang="fr">
<head>
  <title> Acupuncteurs en médecine traditionnelle chinoise </title>
  <meta name="description" content="Acupuncteurs en médecine traditionnelle chinoise" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" media="screen" type="text/css" href="style.css" />
</head>
<body>
  <?php $_smarty_tpl->_subTemplateRender('file:./header.tpl', $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array(), 0, false);
?>



       <header>
       </header>

     <nav>
        <ul>
          <li> <a href="index.php?page=accueil" accesskey="1">Page d'accueil (1) </a> </li>
          <li> <a href="index.php?page=categorie" accesskey="2">Accès aux données (2)</a> </li>
          <li> <a class ="active" href="index.php?page=info" accesskey="3">Page d'information (3)</a> </li>
          <li> <a href="index.php?page=rss" accesskey="4">RSS (4) </a> </li>
          <li accesskey="5" id="connex"> <?php echo smarty_function_connexion(array(),$_smarty_tpl);?>
 </li>

        </ul>
    </nav>

      <div class="gros_titre">
        <h1>ACUPUNCTURE</h1>

        <h2>Page d'information</h2>
      </div>
      <div class="para">

          <p>
            L'acupuncture est une branche proche de la médecine, d'origine chinoise, à la fois naturelle et empirique. L'acupuncture travaille sur l'ensemble du corps et s'appuie sur les grands principes de la médecine asiatique : yin et yang, utilisation des méridiens énergétiques, etc. Cette méthode consiste à introduire sous la peau des aiguilles en métal, qui vont piquer le corps à des endroits bien précis pour provoquer l'action souhaitée sur l'organisme et rétablir l'équilibre énergétique du corps. Elle pourrait s'avérer efficace dans la prévention de troubles fonctionnels ou pour lutter contre des douleurs inflammatoires, des allergies, des eczémas, la dépression et aiderait à l'arrêt du tabac. L'acupuncture est aujourd'hui considérée comme une thérapie complémentaire efficace dans le traitement de nombreux troubles. Le point sur les indications thérapeutiques de cette discipline majeure de la médecine chinoise
          </p>
          <h3>Web Service</h3>
          <p>
            Le Web service crée ici est un web service de calculatrice, il vous permet de faire des additions, soustractions,multiplication et divisions.<br/>


            Pour cela il vous suffit de rentrer dans l'URL de votre naviguateur (après le localhost:votreport) : <br/><br/>
            <h4>ADDITION : </h4>  ../calculatrice/addition/1/2 <br/>
              Cette page vous renverra le résultat de 1+2<br/><br/>
            <h4>SOUSTRACTION : </h4> ../calculatrice/soustraction/1/2<br/><br/>
            <h4>DIVISION : </h4>  ../calculatrice/division/1/2<br/><br/>
            <h4>MULTIPLICATION : </h4>  ../calculatrice/multiplication/1/2<br/><br/>
            <h4>EXEMPLE : </h4>  http://localhost:81/calculatrice/multiplication/1/2<br/><br/>


            Ce web service a été ecrit par nos soins.<br/>

            Aide pour redirection erreur 404 : <a href="https://openclassrooms.com/courses/simuler-l-url-rewriting-avec-l-erreur-404">URL-rewriting</a><br/>
          </p>
          <h3>Mise en page</h3>
          <p>
            Image de fond :  <a href="http://wallpaper-gallery.net/wallpapers/china-wallpaper.html">Lac en Chine</a>
          </p>
          <h3>Flux RSS</h3>
          <p>
            Image  :  <a href="http://canope.ac-besancon.fr/formation/esidoc2/rss3.png">RSS</a><br/>
            Tutoriel suivi  :  <a href="https://www.xul.fr/xml-rss.html">Construire et utiliser un fil RSS</a>

          </p>
        </div>


        <?php $_smarty_tpl->_subTemplateRender('file:./footer.tpl', $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array(), 0, false);
?>

</body>

</html>
<?php }
}
