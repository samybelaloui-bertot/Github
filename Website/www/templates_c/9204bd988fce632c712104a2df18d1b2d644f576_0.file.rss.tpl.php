<?php
/* Smarty version 3.1.31, created on 2017-04-02 15:18:19
  from "C:\wamp\www\rss.tpl" */

/* @var Smarty_Internal_Template $_smarty_tpl */
if ($_smarty_tpl->_decodeProperties($_smarty_tpl, array (
  'version' => '3.1.31',
  'unifunc' => 'content_58e1163bd10299_22732286',
  'has_nocache_code' => false,
  'file_dependency' => 
  array (
    '9204bd988fce632c712104a2df18d1b2d644f576' => 
    array (
      0 => 'C:\\wamp\\www\\rss.tpl',
      1 => 1491146291,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
    'file:./header.tpl' => 1,
    'file:./footer.tpl' => 1,
  ),
),false)) {
function content_58e1163bd10299_22732286 (Smarty_Internal_Template $_smarty_tpl) {
if (!is_callable('smarty_function_connexion')) require_once 'C:\\wamp\\www\\smarty\\plugins\\function.connexion.php';
?>
<!DOCTYPE html>

<html lang="fr">
<head>
  <title> Acupuncteurs en médecine traditionnelle chinoise </title>
  <meta name="description" content="Acupuncteurs en médecine traditionnelle chinoise" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" media="screen" type="text/css" href="style.css" />
  <?php echo '<script'; ?>
 src="jquery-3.2.0.min.js" type="text/javascript"><?php echo '</script'; ?>
>
  <?php $_smarty_tpl->_subTemplateRender('file:./header.tpl', $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array(), 0, false);
?>


<body>

         <nav>
          <ul>
            <li> <a  accesskey="1" href="index.php?page=accueil">Page d'accueil (1) </a> </li>
            <li> <a accesskey="2" href="index.php?page=categorie">Accès aux données (2)</a> </li>
            <li> <a accesskey="3" href="index.php?page=info">Page d'information (3) </a> </li>
            <li> <a class="active" accesskey="4" href="index.php?page=rss">RSS (4)</a> </li>
            <li accesskey="5" id="connex"> <?php echo smarty_function_connexion(array(),$_smarty_tpl);?>
 </li>
          </ul>
         </nav>
         <div class="gros_titre">
           <h1>ACUPUNCTURE</h1>

           <h2>RSS</h2>
           <img src="images/rss.png" alt="image de flux RSS" height="42" width="42">

         </div>

      <div id="Div_XML"></div>
      <?php echo '<script'; ?>
 type="text/javascript">
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


  <?php echo '</script'; ?>
>


</body>

<?php $_smarty_tpl->_subTemplateRender('file:./footer.tpl', $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array(), 0, false);
?>

<?php }
}
