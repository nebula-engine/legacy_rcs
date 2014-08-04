MARINE * lookup_marine_tag_2_pointer_recursive( TAG tag, int level, ORG_MAP_LEVEL * om_level )
{
    if ( level == 0 )
    {
        return om_level->m;
    }
    if ( tag.a[level-1] == -1 )
    {
        return om_level->m;
    }
    else
    {
        return lookup_marine_tag_2_pointer_recursive( tag, level-1, om_level->level[tag.a[level-1]] );
    }
}

MARINE * lookup_marine_tag_2_pointer( GAME * g, TAG tag )
{
    int level = 3;
    return lookup_marine_tag_2_pointer_recursive( tag, level, g->level[tag.a[level]] );
}

MARINE * lookup_marine_id_2_pointer( GAME * g, int id )
{
    for ( std::vector<MARINE*>::iterator it = g->marines.begin(); it != g->marines.end(); it++ )
	{
        if ( (*it)->id == id )
        {
            return (*it);
        }
    }
	swprintf_s( msgbox_tchar, _T("lookup_marine_tag_2_pointer marine not found %i"), id );
    MessageBox( NULL, msgbox_tchar, NULL, 0 );
    return NULL;
}
