<?php
/* Smarty version 3.1.31, created on 2017-04-02 15:22:51
  from "C:\wamp64\www\categorie.tpl" */

/* @var Smarty_Internal_Template $_smarty_tpl */
if ($_smarty_tpl->_decodeProperties($_smarty_tpl, array (
  'version' => '3.1.31',
  'unifunc' => 'content_58e1174ba13867_42161214',
  'has_nocache_code' => false,
  'file_dependency' => 
  array (
    '79d09799e71e16dc056f2338106ca4ad081314d2' => 
    array (
      0 => 'C:\\wamp64\\www\\categorie.tpl',
      1 => 1491145849,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
    'file:./header.tpl' => 1,
    'file:./footer.tpl' => 1,
  ),
),false)) {
function content_58e1174ba13867_42161214 (Smarty_Internal_Template $_smarty_tpl) {
if (!is_callable('smarty_function_connexion')) require_once 'C:\\wamp64\\www\\smarty\\plugins\\function.connexion.php';
if (!is_callable('smarty_function_filtre_categorie')) require_once 'C:\\wamp64\\www\\smarty\\plugins\\function.filtre_categorie.php';
if (!is_callable('smarty_function_pathologie')) require_once 'C:\\wamp64\\www\\smarty\\plugins\\function.pathologie.php';
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" >

  <title> Acupuncteurs en médecine traditionnelle chinoise </title>
  <meta name="description" content="Acupuncteurs en médecine traditionnelle chinoise" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" media="screen" type="text/css" href="style.css" />

  <?php $_smarty_tpl->_subTemplateRender('file:./header.tpl', $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array(), 0, false);
?>


  <body>


     <nav>
        <ul>
          <li> <a accesskey="1" href="index.php?page=accueil">Page d'accueil (1) </a> </li>
          <li> <a class="active"  accesskey="2" href="index.php?page=categorie">Accès aux données (2)</a> </li>
          <li> <a accesskey="3" href="index.php?page=info">Page d'information (3) </a> </li>
          <li> <a accesskey="4" href="index.php?page=rss">RSS (4)</a> </li>
          <li id="connex" accesskey="5"> <?php echo smarty_function_connexion(array(),$_smarty_tpl);?>
 </li>

        </ul>
     </nav>
     <div class="gros_titre">
       <h1>ACUPUNCTURE</h1>

       <h2>Liste des pathologies</h2>
     </div>
      <?php if (isset($_SESSION['login'])) {?>
        <h3> Filtrage </h3>
          <form method="post" id='recherche' action="index.php?page=categorie">
                <label for="champ_recherche">Recherche par mots clés: </label>
                <input type="text" id="champ_recherche" name="champ_recherche"/>

               <?php echo smarty_function_filtre_categorie(array(),$_smarty_tpl);?>


               <label>Méridien:</label>
               <select name="meridien" id="meridien">
                  <option value=""> Aucun </option>
                  <?php
$_from = $_smarty_tpl->smarty->ext->_foreach->init($_smarty_tpl, $_smarty_tpl->tpl_vars['liste_categorie']->value, 'categorie');
if ($_from !== null) {
foreach ($_from as $_smarty_tpl->tpl_vars['categorie']->value) {
?>
                     <option value="<?php echo $_smarty_tpl->tpl_vars['categorie']->value['Categorie'];?>
"> <?php echo $_smarty_tpl->tpl_vars['categorie']->value['Categorie'];?>
 </option>
                  <?php
}
}
$_smarty_tpl->smarty->ext->_foreach->restore($_smarty_tpl, 1);
?>

               </select>

               <label>Type de pathologie:</label>
               <select name="type" id="type">
                      <option value=""> Aucun </option>
                      <option value="meridien"> méridien </option>
                      <option value="meridien"> organe/viscere </option>
                      <option value="luo"> luo </option>
                      <option value="merveilleux vaisseaux"> merveilleux vaisseaux </option>
                      <option value="jing jin"> jing jin </option>
                </select>

                <label>Caractéristiques:</label>
                 <select name="caracteristique" id="caracteristique">
                       <option value=""> Aucune </option>
                       <option value="plein"> plein </option>
                       <option value="chaud"> chaud </option>
                       <option value="vide"> vide </option>
                       <option value="froid"> froid </option>
                       <option value="interne"> interne </option>
                       <option value="externe"> externe </option>
                </select>
               <input type="submit" value="Rechercher"/>
        </form>
      <?php }?>

     <h3> Affichage </h3>

      <?php echo smarty_function_pathologie(array(),$_smarty_tpl);?>

      <table>
          <thead>
              <tr>
                  <th id="pathologie">Pathologie</th>
                  <th id="symptome">Symptome</th>
              </tr>
          </thead>
          <tbody class="tableau">
              <?php
$_from = $_smarty_tpl->smarty->ext->_foreach->init($_smarty_tpl, $_smarty_tpl->tpl_vars['liste_patho']->value, 'patho');
if ($_from !== null) {
foreach ($_from as $_smarty_tpl->tpl_vars['patho']->value) {
?>
                <tr>
                  <td><?php echo $_smarty_tpl->tpl_vars['patho']->value['Pathologie'];?>
 </td>
                  <td><?php echo $_smarty_tpl->tpl_vars['patho']->value['Symptome'];?>
 </td>
                </tr>
             <?php
}
}
$_smarty_tpl->smarty->ext->_foreach->restore($_smarty_tpl, 1);
?>

        </tbody>
      </table>


      <?php $_smarty_tpl->_subTemplateRender('file:./footer.tpl', $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array(), 0, false);
?>


    <?php echo '<script'; ?>
 src="https://code.jquery.com/jquery-1.12.4.js"><?php echo '</script'; ?>
>
    <?php echo '<script'; ?>
 src="https://code.jquery.com/ui/1.12.1/jquery-ui.js"><?php echo '</script'; ?>
>
    <?php echo '<script'; ?>
 type='text/javascript' src='/filtre.js'><?php echo '</script'; ?>
>

  </body>
</html>
<?php }
}
